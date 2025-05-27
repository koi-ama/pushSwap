#!/usr/bin/env bash
# ============================================================
# push_swap_full_tester.sh  –  42 “push_swap” peer-review helper
# ------------------------------------------------------------
#  • Runs (almost) every checklist item from the evaluation PDF
#  • Needs:  bash, python3, grep, wc, valgrind (optional),
#            ./push_swap  and ./checker (or checker_Mac) built
# ------------------------------------------------------------
#  USAGE
#     ./defence.sh            # mandatory tests only (checker_Mac)
#     ./defence.sh -b         # mandatory + bonus checker tests (./checker)
#     ./defence.sh -b ./push_swap ./checker   # explicit binaries
#
#  EXIT CODE
#     0  everything passed inside the required limits
#     1  at least one test failed (see red ❌ markers)
# ------------------------------------------------------------
#  Author:  (fill your name)
# ============================================================

# -------- logging ---------
LOGDIR="./defence_logs"
mkdir -p "$LOGDIR"
LOGFILE="$LOGDIR/$(date '+%Y-%m-%d_%H-%M-%S').log"
# Colourised STDOUT goes to terminal; de‑colourised copy goes to the log file
exec > >(tee >(sed -r 's/\x1B\[[0-9;]*[JKmsu]//g' >>"$LOGFILE"))
echo "Log file: $LOGFILE"
# --------------------------

# -------- option parser ---------
BONUS=0
if [[ ${1:-} == "-b" ]]; then
  BONUS=1
  shift
fi
# --------------------------------

set -euo pipefail
PSW=${1:-./push_swap}

# Two separate checkers:
CHK_MAND="./checker_Mac"          # used for mandatory runs
CHK_BONUS="./checker"             # used for bonus checker tests

# allow override from CLI: ./defence.sh [-b] [push_swap] [checker_MAND]
[[ -n ${2:-} ]] && CHK_MAND=$2
RED=$'\e[31m'; GRN=$'\e[32m'; YLW=$'\e[33m'; CLR=$'\e[0m'
FAIL=0

# ---------- helpers ----------------------------------------------------------
rand_list() { python3 - <<PY "$@"
import random,sys
n=int(sys.argv[1]); r1=int(sys.argv[2]); r2=int(sys.argv[3])
print(*random.sample(range(r1,r2+1),n))
PY
}

DEF_COLOR='\033[0;39m'
MAGENTA='\033[0;95m'

print_ok()  { printf "  ${GRN}✔ %s${CLR}\n" "$1"; }
print_fail(){ printf "  ${RED}❌ %s${CLR}\n" "$1"; FAIL=1; }

moves() { wc -l; }                    # counts stdin lines

run() {                               # $1: list  $2: checker
  local ARG="$1"
  local out moves res
  out=$($PSW $ARG)
  moves=$(printf '%s\n' "$out" | wc -l)
  res=$(printf '%s\n' "$out" | "$2" $ARG \
       | sed -r 's/\x1B\[[0-9;]*[mK]//g' \
       | tr -d '[:space:]' | head -n1)

  # ----- verbose logging -----
  {
    echo
    echo "=== Test case ==="
    echo "Args : $ARG"
    echo "Moves: $moves"
    echo "Checker result: $res"
    echo "Push_swap output:"
    echo "$out"
    echo "================="
  } >>"$LOGFILE"
  # ---------------------------

  echo "$moves $res"
}

printf ${MAGENTA}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t\t Mandatory\t\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

# ---------- 1. build check ---------------------------------------------------
printf "${YLW}== Build check ==${CLR}\n"
make -s >/dev/null && print_ok "make (mandatory)"
make bonus -s >/dev/null && print_ok "make bonus"

# Banner for which checker is used
printf "Mandatory checker : %s\n" "$CHK_MAND"
printf "Bonus checker      : %s\n" "$CHK_BONUS"

# ---------- 2. error-management tests ---------------------------------------
printf "${YLW}\n== Error management ==${CLR}\n"
errs=(
  "abc 1 2"
  "1 2 2"
  "2147483648"
)
for e in "${errs[@]}"; do
  out="$($PSW $e 2>&1 || true)"
  echo "$out" | tee -a "$LOGFILE"       # ログへ書き込み
  if [[ $out == *Error* ]]; then
    print_ok "\"$e\" -> Error"
  else
    print_fail "\"$e\" should print Error"
  fi
done
$PSW >/dev/null && print_ok "no-arg prints nothing"

# ---------- 3. identity tests -----------------------------------------------
printf "${YLW}\n== Identity tests ==${CLR}\n"
id_lists=(
  "42"
  "2 3"
  "0 1 2 3"
  "0 1 2 3 4 5 6 7 8 9"
)
for l in "${id_lists[@]}"; do
  if [[ -z $($PSW $l) ]]; then print_ok "$l"; else print_fail "$l not empty"; fi
done

# ---------- 4. simple version (0-5 values) ----------------------------------
printf "${YLW}\n== Simple version (3-5 vals) ==${CLR}\n"
simple1="2 1 0"
read m res < <(run "$simple1" "$CHK_MAND")
[[ $res == "OK" && $m -le 3 ]] && print_ok "$simple1 ($m)" || print_fail "$simple1 ($m)"

simple_rand=$(rand_list 5 0 100)
read m res < <(run "$simple_rand" "$CHK_MAND")
[[ $res == "OK" && $m -le 12 ]] && print_ok "rand5 ($m)" || print_fail "rand5 ($m)"

# ---------- 5. intermediate (100 vals) --------------------------------------
printf "${YLW}\n== Intermediate (100 vals) ==${CLR}\n"
i_list=$(rand_list 100 0 999)
read m res < <(run "$i_list" "$CHK_MAND")
if [[ $res == "OK" && $m -lt 700 ]]; then  score=5
elif [[ $res == "OK" && $m -lt 900 ]]; then score=4
elif [[ $res == "OK" && $m -lt 1100 ]]; then score=3
elif [[ $res == "OK" && $m -lt 1300 ]]; then score=2
elif [[ $res == "OK" && $m -lt 1500 ]]; then score=1
else score=0; FAIL=1
fi
printf "  moves=%s  => score %s/5\n" "$m" "$score"

# ---------- 6. advanced (500 vals) ------------------------------------------
printf "${YLW}\n== Advanced (500 vals) ==${CLR}\n"
a_list=$(rand_list 500 0 4999)
read m res < <(run "$a_list" "$CHK_MAND")
if [[ $res == "OK" && $m -lt 5500 ]]; then score=5
elif [[ $res == "OK" && $m -lt 7000 ]]; then score=4
elif [[ $res == "OK" && $m -lt 8500 ]]; then score=3
elif [[ $res == "OK" && $m -lt 10000 ]]; then score=2
elif [[ $res == "OK" && $m -lt 11500 ]]; then score=1
else score=0; FAIL=1
fi
printf "  moves=%s  => score %s/5\n" "$m" "$score"

if [[ $BONUS -eq 1 ]]; then
  printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
  printf ${MAGENTA}"\n\t\t\t  BONUS\t\t\n"${DEF_COLOR};
  printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
fi

# ---------- Checker tests ---------------------------------------------------
if [[ $BONUS -eq 1 ]]; then
printf "${YLW}\n== Checker error‑management ==${CLR}\n"
bad_args=("abc 1" "1 1" "2147483648")
for a in "${bad_args[@]}"; do
  if [[ $($CHK_BONUS $a 2>&1) == Error* ]]; then
    print_ok "checker bad‑arg \"$a\" -> Error"
  else
    print_fail "checker bad‑arg \"$a\""
  fi
done
$CHK_BONUS >/dev/null && print_ok "checker no‑arg silence" \
                 || print_fail "checker no‑arg"

printf "${YLW}\n== Checker invalid actions ==${CLR}\n"

# 1) unknown action
if ( printf "xx\n" | $CHK_BONUS 1 2 3 2>&1 || true ) | grep -q Error; then
  print_ok "unknown action"
else
  print_fail "unknown action"
fi

# 2) spaces before / after
if ( printf "  sa \n" | $CHK_BONUS 1 2 3 2>&1 || true ) | grep -q Error; then
  print_ok "space action"
else
  print_fail "space action"
fi

printf "${YLW}\n== Checker false / right tests ++ ==${CLR}\n"
printf "sa\npb\nrrr\n" | $CHK_BONUS 0 9 1 8 2 7 3 6 4 5 | grep -q KO \
   && print_ok "false‑KO list1" || print_fail "false‑KO list1"
RAND=$(seq 0 100 | shuf | head -n 5 | tr '\n' ' ')
printf "sa\n" | $CHK_BONUS $RAND | grep -q KO \
   && print_ok "false‑KO random" || print_fail "false‑KO random"
printf "" | $CHK_BONUS 0 1 2 | grep -q OK \
   && print_ok "right‑OK empty" || print_fail "right‑OK empty"
RARG=$(shuf -i 0-100 -n 5 | tr '\n' ' ')
RIGHT=$($PSW $RARG)
echo "$RIGHT" | $CHK_BONUS $RARG | grep -q OK \
   && print_ok "right‑OK random" || print_fail "right‑OK random"
fi
printf "${YLW}\n== Checker tests ==${CLR}\n"
printf "sa\npb\nrrr\n" | $CHK_BONUS 0 9 1 8 2 7 3 6 4 5 | grep -q KO \
   && print_ok "checker false-KO" || print_fail "checker false"

printf "pb\nra\npb\nra\nsa\nra\npa\npa\n" | $CHK_BONUS 0 9 1 8 2 | grep -q OK \
   && print_ok "checker right-OK" || print_fail "checker right"

# ---------- 8. memory leaks (optional) --------------------------------------
if command -v valgrind &>/dev/null; then
  printf "${YLW}\n== Valgrind leak check (short run) ==${CLR}\n"
  valgrind --leak-check=full --error-exitcode=42 $PSW $simple1 >/dev/null 2>&1 \
     && print_ok "no leaks" || print_fail "leaks!"
fi

# ---------- summary ----------------------------------------------------------
echo -e "\n==============================================="
if [[ $FAIL -eq 0 ]]; then
  if [ "$BONUS" = 1 ]; then
    echo "All mandatory & bonus checks passed 🥳 🎉 ☺️ ✅"
  else
    echo "All mandatory checks passed ✅"
  fi
  exit 0
else
  echo -e "${RED}Some tests failed — see ❌ above${CLR}"
  exit 1
fi