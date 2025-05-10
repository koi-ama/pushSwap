Push_swap
Because Swap_push do esn't feel as natural
Summary:
In this project, you wil l sort data in a stack using a limited set of instructions, aiming
to achieve the lowest possible number of actions. To succeed, you wil l need to work with
various algorithms and choose the most appropriate one for optimized data sorting.
Version: 8.4


Contents
I Foreword
 2
I I Intro duction
 4
I I I Ob jectives
 5
IV Common Instructions
 6
V Mandatory part
 8
V.1 The rules
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 8
V.2 Example
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9
V.3 The "push_swap" program
 . . . . . . . . . . . . . . . . . . . . . . . . 10
V.4 Benchmark
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 12
VI Bonus part
 13
VI.1 The "checker" program
 . . . . . . . . . . . . . . . . . . . . . . . . . . 14
VI I Submission and p eer-evaluation
 16
1


Chapter I
Foreword

C
#include <stdio.h>
int main(void)
{
printf("hello, world\n");
return 0;
}

ASM
cseg segment
assume cs:cseg, ds:cseg
org 100h
main proc
jmp debut
mess db
'
Hello world!$
'
debut:
mov dx, offset mess
mov ah, 9
int 21h
ret
main endp
cseg ends
end main

LOLCODE
HAI
CAN HAS STDIO?
VISIBLE "HELLO WORLD!"
KTHXBYE

PHP
<?php
echo "Hello world!";
?>

BrainFuck
++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.
<<+++++++++++++++.>.+++.------.--------.>+.>.
2


Push_swap B ecause Swap_push do esn't feel as natural

C#
using System;
public class HelloWorld {
public static void Main () {
Console.WriteLine("Hello world!");
}
}

HTML5
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Hello world !</title>
</head>
<body>
<p>Hello World !</p>
</body>
</html>

YASL
"Hello world!"
print

OCaml
let main () =
print_endline "Hello world !"
let _ = main ()
3


Chapter I I
Intro duction
The
Push swap
pro ject is a simple yet highly structured algorithmic challenge: you
need to sort data.
You have at your disp os al a set of integer values, 2 stacks, and a set of instructions to
manipulate b oth stacks.
Your goal? Write a C program called
push_swap
that calculates and displays the
shortest sequence of Push_swap instructions needed to sort the given integers.
Easy?
We'll see...
4


Chapter I I I
Ob jectives
Writing a sorting algorithm is always a crucial step in a develop er's journey. It is often
the ˝rst encounter with the concept of
 complexity
.
Sorting algorithms and their complexities are common topics in job interviews. Now is a
great time to explore these concepts, as you will likely encounter them in the future.
The learning ob jectives of this pro ject are rigor, pro˝ciency in
C
, and the application of
basic algorithms, with a particular fo cus on their complexity.
Sorting values is straightforward, but ˝nding the fastest way to sort them is more chal-
lenging. The most e˚cient sorting metho d can vary dep ending on the arrangement of
integers.
5


Chapter IV
Common Instructions

Your pro ject must b e written in C.

Your pro ject must b e written in accordance with the Norm. If you have b onus
˝les/functions, they are included in the norm check, and you will receive a
0
if
there is a norm error.

Your functions should not quit unexp ectedly (segmentation fault, bus error, dou-
ble free, etc.) except for unde˝ned b ehavior. If this o ccurs, your pro ject will b e
considered non-functional and will receive a
0
during the evaluation.

All heap-allo cated memory must b e prop erly freed when necessary. Memory leaks
will not b e tolerated.

If the sub ject requires it, you must submit a
Makefile
that compiles your source
˝les to the required output with the ˛ags
-Wall
,
-Wextra
, and
-Werror
, using
cc
.
Additionally, your
Makefile
must not p erform unnecessary relinking.

Your
Makefile
must contain at least the rules
$(NAME)
,
all
,
clean
,
fclean
and
re
.

To submit b onuses for your pro ject, you must include a
bonus
rule in your
Makefile
,
which will add all the various headers, libraries, or functions that are not allowed in
the main part of the pro ject. Bonus es must b e placed in
_bonus.{c/h}
˝les, unless
the sub ject sp eci˝es otherwise. The evaluation of mandatory and b onus parts is
conducted separately.

If your pro ject allows you to use your
libft
, you must copy its sources and its
asso ciated
Makefile
into a
libft
folder. Your pro ject's
Makefile
must compile
the library by using its
Makefile
, then compile the pro ject.

We encourage you to create test programs for your pro ject, even though this work
do es not need to b e submitted and will not b e grade d
. It will give you an
opp ortunity to easily test your work and your p eers' work. You will ˝nd these tests
esp ecially useful during your defence. Indeed, during defence, you are free to use
your tests and/or the tests of the p eer you are evaluating.

Submit your work to the assigned Git rep ository. Only the work in the Git rep os-
itory will b e graded. If Deepthought is assigned to grade your work, it will o ccur
6


Push_swap B ecause Swap_push do esn't feel as natural
after your p eer-evaluations. If an error happ ens in any section of your work during
Deepthought's grading, the evaluation will stop.
7


Chapter V
Mandatory part
V.1 The rules

You have 2
 stacks
 named
a
and
b
.

At the b eginning:

The stack
a
contains a random numb er of unique negative and/or p ositive
integers.

The stack
b
is empty.

The goal is to sort the numb ers in stack
a
in ascending order. To achieve this, you
have the following op erations at your disp osal:
sa
(
swap a
): Swap the ˝rst 2 elements at the top of stack
a
.
Do nothing if there is only one element or none.
sb
(
swap b
): Swap the ˝rst 2 elements at the top of stack
b
.
Do nothing if there is only one element or none.
ss
:
sa
and
sb
at the same time.
pa
(
push a
): Take the ˝rst element at the top of
b
and put it at the top of
a
.
Do nothing if
b
is empty.
pb
(
push b
): Take the ˝rst element at the top of
a
and put it at the top of
b
.
Do nothing if
a
is empty.
ra
(
rotate a
): Shift up all elements of stack
a
by 1.
The ˝rst element b ecomes the las t one.
rb
(
rotate b
): Shift up all elements of stack
b
by 1.
The ˝rst element b ecomes the las t one.
rr
:
ra
and
rb
at the same time.
rra
(
reverse rotate a
): Shift down all elements of stack
a
by 1.
The last element b ecomes the ˝rs t one.
rrb
(
reverse rotate b
): Shift down all elements of stack
b
by 1.
The last element b ecomes the ˝rst one.
rrr
:
rra
and
rrb
at the same time.
8


Push_swap B ecause Swap_push do esn't feel as natural
V.2 Example
To illustrate the e˙ect of some of these instructions, let's sort a random list of integers.
In this example, we'll consider that b oth stacks grow from the right.
----------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
The integers in stack
a
get sorted in 12 instructions. Can you do b etter?
9


Push_swap B ecause Swap_push do esn't feel as natural
V.3 The "push_swap" program
Program name
push_swap
Turn in ˝les
Makefile, *.h, *.c
Make˝le
NAME, all, clean, fclean, re
Arguments
stack a: A list of integers
External functs.

read, write, malloc, free,
exit

ft_printf or any equivalent
YOU coded
Libft authorized
Yes
Description
Sort stacks
Your pro ject must comply with the following rules:

You have to turn in a
Makefile
which will compile your source ˝les. It must not
relink.

Global variables are forbidden.

You have to write a program named
push_swap
that takes as an argument the stack
a
formatted as a list of integers. The ˝rst argument should b e at the top of the
stack (b e careful ab out the order).

The program must display the shortest sequence of instructions needed to sort stack
a
with the smallest numb er at the top.

Instructions must b e separated by a '\n' and nothing else.

The goal is to sort the stack with the lowest p ossible numb er of op erations. During
the evaluation pro cess, the numb er of instructions found by your program will b e
compared against a limit: the maximum numb er of op erations tolerated. If your
program either displays a longer list or if the numb ers aren't sorted prop erly, your
grade will b e 0.

If no parameters are sp eci˝ed, the program must not display anything and should
return to the prompt.

In case of error, it must display
"Error"
followed by an '\n' on the standard error.
Errors include, for example: some arguments not b eing integers, some arguments
exceeding the integer limits, and/or the presence of duplicates.
10


Push_swap B ecause Swap_push do esn't feel as natural
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
During the evaluation pro cess, a binary will b e provided in order to prop erly check
your program.
It will work as follows:
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
If the program
checker_OS
displays
"KO"
, it means that your
push_swap
came up
with a list of instructions that do esn't sort the numb ers.
The checker_OS program is available in the resources of the project
in the intranet.
You can find a description of how it works in the Bonus Part of this
document.
11


Push_swap B ecause Swap_push do esn't feel as natural
V.4 Benchmark
To validate this pro ject, you must p erform certain sorts with a minimal numb er of op er-
ations:

For
maximum pro ject validation
(100%) and eligibility for b onuses, you must:

Sort
100 random numb ers in fewer than 700 op erations
.

Sort
500 random numb ers in no more than 5500 op erations
.

For
minimal pro ject validation
(which implies a minimum grade of 80%), you
can succeed with di˙erent averages:

100 numb ers in under 1100 op erations
and
500 numb ers in under
8500 op erations

100 numb ers in under 700 op erations
and
500 numb ers in under
11500 op erations

100 numb ers in under 1300 op erations
and
500 numb ers in under
5500 op erations
...
All of this will b e veri˝ed during your evaluation.
If you wish to complete the bonus part, you must thoroughly validate
the project with each benchmark step achieving the highest possible
score.
12


Chapter VI
Bonus part
Due to its simplicity, this pro ject o˙ers limited opp ortunities for additional features.
However, why not create your own checker?
Thanks to the checker program, you will be able to check whether
the list of instructions generated by the push_swap program actually
sorts the stack properly.
The bonus part will only be assessed if the mandatory part is
perfect. Perfect means the mandatory part has been fully completed
and functions without errors. In this project, this entails
validating all benchmarks without exception. If you have not
passed ALL the mandatory requirements,b your bonus part will not
be evaluated at all.
13


Push_swap B ecause Swap_push do esn't feel as natural
VI.1 The "checker" program
Program name
checker
Turn in ˝les
*.h, *.c
Make˝le
bonus
Arguments
stack a: A list of integers
External functs.

read, write, malloc, free,
exit

ft_printf or any equivalent
YOU coded
Libft authorized
Yes
Description
Execute the sorting instructions

Write a program named
checker
that takes as an argument the stack
a
formatted
as a list of integers. The ˝rst argument should b e at the top of the stack (b e careful
ab out the order). If no argument is given, it stops and displays nothing.

It will then wait and read instructions from the standard input, with each instruc-
tion followed by '\n'. Once all the instructions have b een read, the program has to
execute them on the stack received as an argument.

If after executing those instructions, the stack
a
is actually sorted and the stack
b
is empty, then the program must display
"OK"
followed by a '\n' on the standard
output.

In every other case, it must display
"KO"
followed by a '\n' on the standard output.

In case of error, you must display
"Error"
followed by a '\n' on the
standard er-
ror
. Errors include for example: some arguments are not integers, some arguments
are bigger than an integer, there are duplicates, an instruction do esn't exist and/or
is incorrectly formatted.
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>./checker "" 1
Error
$>
14


Push_swap B ecause Swap_push do esn't feel as natural
You DO NOT have to reproduce the exact same behavior as the provided
binary. It is mandatory to manage errors but it is up to you to
decide how you want to parse the arguments.
15


Chapter VI I
Submission and p eer-evaluation
Submit your assignment in your
Git
rep ository as usual. Only the work inside your rep os-
itory will b e evaluated during the defense. Don't hesitate to double check the names of
your ˝les to ensure they are correct.
As these assignments are not veri˝ed by a program, feel free to organize your ˝les as
you wish, as long as you turn in the mandatory ˝les and comply with the requirements.
file.bfe:VABB7yO9xm7xWXROeASsmsgnY0o0sDMJev7zFHhwQS8mvM8V5xQQp
Lc6cDCFXDWTiFzZ2H9skYkiJ/DpQtnM/uZ0
16


