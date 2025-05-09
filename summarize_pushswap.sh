#!/bin/bash

PROJECT_DIR="/Users/koiama/Desktop/Invest/Codes/42/cursus/pushSwap"
OUTPUT_FILE="project_summary.md"

echo "# push_swap Project Summary" > "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"
echo "## Directory Structure" >> "$OUTPUT_FILE"
echo '```' >> "$OUTPUT_FILE"

cd "$PROJECT_DIR" || exit 1

# push_swap_tester ディレクトリを除外してディレクトリ構造を再構築
find . -type d -name push_swap_tester -prune -o -print | grep -v '/push_swap_tester' | while read -r path; do
    if [[ -d "$path" ]]; then
        indent=$(echo "$path" | grep -o "/" | wc -l)
        printf "%*s%s\n" $((indent * 4)) "" "${path#./}"
    elif [[ -f "$path" ]]; then
        dir=$(dirname "$path")
        indent=$(echo "$dir" | grep -o "/" | wc -l)
        printf "%*s├── %s\n" $(((indent + 1) * 4)) "" "$(basename "$path")"
    fi
done >> "$OUTPUT_FILE"

echo '```' >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

echo "## File Contents" >> "$OUTPUT_FILE"

# .c, .h, Makefile で push_swap_tester を除外したファイルだけ対象にする
find . -path './push_swap_tester' -prune -o -type f \( -name "*.c" -o -name "*.h" -o -name "Makefile" \) -print | sort | while read -r file; do
    rel_path="${file#./}"
    echo "### $rel_path" >> "$OUTPUT_FILE"
    echo '```c' >> "$OUTPUT_FILE"
    cat "$file" >> "$OUTPUT_FILE"
    echo '```' >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"
done

pbcopy < "$OUTPUT_FILE"
echo "✅ Generated $OUTPUT_FILE (excluding push_swap_tester) and copied to clipboard."