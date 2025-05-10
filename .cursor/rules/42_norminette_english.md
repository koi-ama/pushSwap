The Norm
Version 4.1
Summary: This document describes the applicable standard (Norm) at 42: a
programming standard that de˝nes a set of rules to fol low when writing code. The Norm
applies to al l C projects within the Common Core by default, and to any project where
it's speci˝ed.


Contents
I Foreword
 2
I I Why?
 3
I I I The Norm
 5
I I I .1 Naming
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 5
I I I .2 Formatting
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6
I I I .3 Functions
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 8
I I I .4 Typ edef, struct, enum and union
 . . . . . . . . . . . . . . . . . . . . . 9
I I I .5 Headers - a.k.a include ˝les
 . . . . . . . . . . . . . . . . . . . . . . . . 10
I I I .6 The 42 header - a.k.a start a ˝le with style
 . . . . . . . . . . . . . . . 11
I I I .7 Macros and Pre-pro cessors
 . . . . . . . . . . . . . . . . . . . . . . . . 12
I I I .8 Forbidden stu˙ !
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13
I I I .9 Comments
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 14
I I I .10 Files
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
I I I .11 Make˝le
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
1


Chapter I
Foreword
The
norminette
is a Python and op en source co de that checks Norm compliance of your
source co de. It checks many constraints of the Norm, but not all of them (eg. sub jective
constraints). Unless sp eci˝c lo cal regulations on your campus, the
norminette
prevails
during evaluations on the controlled items. In the following pages, rules that are not
checked by the
norminette
are marked with
(*)
, and can lead to pro ject failure (using
the Norm ˛ag) if discovered by the evaluator during a co de review.
Its rep ository is available at https://github.com/42Scho ol/norminette.
Pull requests, suggestions and issues are welcome!
2


Chapter I I
Why?
The Norm has b een carefully crafted to ful˝ll many p edagogical needs. Here are the most
imp ortant reasons for all the choices b elow:

Sequencing: co ding implies splitting a big and complex task into a long s eries of
elementary instructions. All these instructions will b e executed in sequence: one
after another. A b eginner that starts creating software needs a simple and clear
architecture for their pro ject, with a full understanding of all individual instructions
and the precise order of execution. Cryptic language s yntaxes that do multiple
instructions apparently at the same time are confusing, functions that try to address
multiple tasks mixed in the same p ortion of co de are source of errors.
The Norm asks you to create simple pieces of co de, where the unique task of each
piece can b e clearly understo o d and veri˝ed, and where the sequence of all the
executed instructions leaves no doubt. That's why we ask for 25 lines maximum in
functions, also why
for
,
do .. while
, or ternaries are forbidden.

Lo ok and Feel: while exchanging with your friends and workmates during the nor-
mal p eer-learning pro cess, and also during the p eer-evaluations, you do not want
to sp end time to decrypt their co de, but directly talk ab out the logic of the piece
of co de.
The Norm asks you to use a sp eci˝c lo ok and feel, providing instructions for the
naming of the functions and variables, indentation, brace rules, tab and spaces at
many places... . This will allow you to smo othly have a lo ok at other's co des that
will lo ok familiar, and get directly to the p oint instead of sp ending time reading
the co de b efore understanding it. The Norm also comes as a trademark. As part of
the 42 community, you will b e able to recognize co de written by another 42 student
or alumni when you'll b e in the lab or market.

Long-term vision: making the e˙ort to write understandable co de is the b est way
to maintain it. Each time that someone else, including you, has to ˝x a bug or
add a new feature they won't have to lose their precious time trying to ˝gure out
what it do es if previously you did things in the right way. This will avoid situations
where pieces of co de stop b eing maintained just b ecause it is time-consuming, and
that can make the di˙erence when we talk ab out having a successful pro duct in the
market. The so oner you learn to do so, the b etter.

References: you may think that some, or all, the rules included on the Norm are
arbitrary, but we actually thought and read ab out what to do and how to do it.
3


The Norm Version 4.1
We highly encourage you to Go ogle why the functions should b e short and just do
one thing, why the name of the variables should make sense, why lines shouldn't
b e longer than 80 columns wide, why a function should not take many parameters,
why comments should b e useful, etc.
4


Chapter I I I
The Norm
I I I.1 Naming

A structure's name must start by
s_
.

A typ edef 's name must start by
t_
.

A union's name must start by
u_
.

An enum's name must start by
e_
.

A global's name must start by
g_
.

Identi˝ers, like variables, functions names, user de˝ned typ es, can only contain
lowercases, digits and '_' (snake_case). No capital letters are allowed.

Files and directories names can only contain lowercases, digits and '_' (s nake_case).

Characters that aren't part of the standard ASCI I table are forbidden, except inside
litteral strings and chars.

(*)
All identi˝ers (functions, typ es, variables, etc.) names should b e explicit, or a
mnemonic, should b e readable in English, with each word separated by an under-
score. This applies to macros, ˝lenames and directories as well.

Using global variables that are not marked const or static is forbidden and is con-
sidered a norm error, unless the pro ject explicitly allows them.

The ˝le must compile. A ˝le that do esn't compile isn't exp ected to pass the Norm.
5


The Norm Version 4.1
I I I.2 Formatting

Each function must b e at most 25 lines long, not counting the function's own braces.

Each line must b e at most 80 columns wide, comments included. Warning: a tabu-
lation do esn't count as a single column, but as the numb er of spaces it represents.

Functions must b e separated by an empty line. Comments or prepro cessor instruc-
tions can b e inserted b etween functions. At least an empty line must exists.

You must indent your co de with 4-char-long tabulations. This is not the same as 4
spaces, we're talking ab out real tabulations here (ASCI I char numb er 9). Check that
your co de editor is correctly con˝gured in order to visually get a prop er indentation
that will b e validated by the
norminette
.

Blo cks within braces must b e indented. Braces are alone on their own line, except
in declaration of struct, enum, union.

An empty line must b e empty: no spaces or tabulations.

A line can never end with spaces or tabulations.

You can never have two consecutive empty lines. You can never have two consecu-
tive spaces.

Declarations must b e at the b eginning of a function.

All variable names must b e indented on the same column in their scop e. Note:
typ es are already indented by the containing blo ck.

The asterisks that go with p ointers must b e stuck to variable names.

One single variable declaration p er line.

Declaration and an initialisation cannot b e on the same line, except for global
variables (when allowed), static variables, and constants.

In a function, you must place an empty line b etween variable declarations and the
remaining of the function. No other empty lines are allowed in a function.

Only one instruction or control structure p er line is allowed. Eg.: Assignment in
a control structure is forbidden, two or multiple assignments on the same line is
forbidden, a newline is needed at the end of a control structure, ... .

An instruction or control structure can b e split into multiple lines when needed.
The following lines created must b e indented compared to the ˝rst line, natural
spaces will b e used to cut the line, and if applies, op erators will b e at the b eginning
of the new line and not at the end of the previous one.

Unless it's the end of a line, each comma or semi-colon must b e followed by a space.

Each op erator or op erand must b e separated by one - and only one - space.

Each C keyword must b e followed by a space, except for keywords for typ es (such
as int, char, ˛oat, etc.), as well as sizeof.
6


The Norm Version 4.1

Control structures (if, while..) must use braces, unless they contain a single in-
struction on a single line.
General example:
int
g_global;
typedef
 struct
s_struct
{
char
*
my_string;
int
i;
}
 t_struct;
struct
s_other_struct
;
int
main
(
void
)
{
int
i;
char
c;
return
(i);
}
7


The Norm Version 4.1
I I I.3 Functions

A function can take 4 named parameters at most.

A function that do esn't take arguments must b e explicitly prototyp ed with the
word "void" as the argument.

Parameters in functions' prototyp es must b e named.

You can't declare more than 5 variables p er function.

Return of a function has to b e b etween parenthesis, unless the function returns
nothing.

Each function must have a s ingle tabulation b etween its return typ e and its name.
int
my_func
(
int
arg1,
char
arg2,
char
*
arg3)
{
return
(my_val);
}
int
func2
(
void
)
{
return
;
}
8


The Norm Version 4.1
I I I.4 Typ ede f, struct, enum and union

As other C keywords , add a space b etween struct and the name when declaring
a struct. Same applies to enum and union.

When declaring a variable of typ e struct, apply the usual indentation for the name
of the variable. Same applies to enum and union.

Inside the braces of the struct, enum, union, regular indentation rules apply, like
any other blo cks.

As other C keywords, add a space after typ edef , and apply regular indentation
for the new de˝ned name.

You must indent all structures' names on the same column for their scop e.

You cannot declare a structure in a .c ˝le.
9


The Norm Version 4.1
I I I.5 He ade rs - a.k.a include ˝les

(*)
The allowed elements of a header ˝le are: header inclusions (system or not),
declarations, de˝nes, prototyp es and macros.

All includes mus t b e at the b eginning of the ˝le.

You cannot include a C ˝le in a header ˝le or another C ˝le.

Header ˝les must b e protected from double inclusions. If the ˝le is
ft_foo.h
, its
bystander macro is
FT_FOO_H
.

(*)
Inclusion of unused headers is forbidden.

Header inclusion can b e justi˝ed in the .c ˝le and in the .h ˝le itself using comments.
#ifndef FT_HEADER_H
# define FT_HEADER_H
#
 include
 <stdlib.h>
#
 include
 <stdio.h>
# define FOO "bar"
int
g_variable;
struct
s_struct
;
#endif
10


The Norm Version 4.1
I I I.6 T he 42 header - a.k.a start a ˝le with style

Every .c and .h ˝le must immediately b egin with the standard 42 header: a multi-
line comment with a sp ecial format including useful informations. The standard
header is naturally available on computers in clusters for various text editors (emacs:
using
C-c C-h
, vim using
:Stdheader
or
F1
, etc...).

(*)
The 42 header must contain several informations up-to-date, including the cre-
ator with login and student email (@student.campus), the date of creation, the login
and date of the last up date. Each time the ˝le is saved on disk, the information
should b e automatically up dated.
The default standard header may not automatically be configured with
your personnal information. You may need to change it to follow the
previous rule.
11


The Norm Version 4.1
I I I.7 Macros and Pre -pro cessors

(*)
Prepro cessor constants (or #de˝ne) you create must b e used only for literal
and constant values.

(*)
All #de˝ne created to bypass the norm and/or obfuscate co de are forbidden.

(*)
You can use macros available in standard libraries, only if those ones are allowed
in the scop e of the given pro ject.

Multiline macros are forbidden.

Macro names must b e all upp ercase.

You must indent prepro cessor directives ins ide #if, #ifdef or #ifndef blo cks.

Prepro cessor instructions are forbidden outside of global scop e.
12


The Norm Version 4.1
I I I.8 Forbidden stu˙ !

You're not allowed to use:

for

do...while

switch

case

goto

Ternary op erators such as ` ?'.

VLAs - Variable Length Arrays.

Implicit typ e in variable declarations
int
main
(
int
argc,
char
**
argv)
{
int
i;
char
str[argc];
// This is a VLA
i
 =
 argc
 >
 5
 ?
 0
 :
 1
// Ternary
}
13


The Norm Version 4.1
I I I.9 Com ments

Comments cannot b e inside function b o dies. Comments must b e at the end of a
line, or on their own line

(*)
Your comments should b e in English, and useful.

(*)
A comment cannot justify the creation of a carryall or bad function.
A carryall or bad function usually comes with names that are not
explicit such as f1, f2... for the function and a, b, c,.. for
the variables names. A function whose only goal is to avoid the
norm, without a unique logical purpose, is also considered as a
bad function. Please remind that it is desirable to have clear and
readable functions that achieve a clear and simple task each. Avoid
any code obfuscation techniques, such as the one-liner, ... .
14


The Norm Version 4.1
I I I.10 Files

You cannot include a .c ˝le in a .c ˝le.

You cannot have more than 5 function-de˝nitions in a .c ˝le.
15


The Norm Version 4.1
I I I.11 Make˝le
Make˝les aren't checked by the
norminette
, and must b e checked during evaluation by
the student when asked by the evaluation guidelines. Unless sp eci˝c instructions, the
following rules apply to the Make˝les:

The
$(NAME)
,
clean
,
fclean
,
re
and
al l
rules are mandatory. The
al l
rule must b e
the default one and executed when typing just
make
.

If the make˝le relinks when not necessary, the pro ject will b e considered non-
functional.

In the case of a multibinary pro ject, in addition to the ab ove rules, you must have
a rule for each binary (eg: $(NAME_1), $(NAME_2), ...). The all rule will
compile all the binaries, using each binary rule.

In the case of a pro ject that calls a function from a non-system library (e.g.:
libft
)
that exists along your source co de, your make˝le must compile this library auto-
matically.

All source ˝les needed to compile your pro ject must b e explicitly named in your
Make˝le. Eg: no *.c, no *.o , etc ...
16


