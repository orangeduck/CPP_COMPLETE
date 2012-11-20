BRAINFUCK
=========

A Brainfuck interpreter written in the C preprocessor.

There has been much speculation on the turing completeness of the C Preprocessor, but I believe ~~this is the first demonstrative proof that the C preprocessor _is_ turing complete~~**. This uses no GCC extensions and other than the rules for macro evaluation the only "features" it takes advantage of are token pasting and variable argument macros.

Thanks to [pfultz](https://github.com/pfultz2/Cloak/wiki/Is-the-C-preprocessor-Turing-complete%3F) and the many others for their contributions and ideas on recursion in the C preprocessor.

** I stand corrected! [Vesa Karvonen](http://chaos-pp.cvs.sourceforge.net/viewvc/chaos-pp/order-pp/), one of the authors of Boost.PP beat me to it by implementing a lisp like dialect in the CPP. Another Brainfuck in CPP implementation also exists by [kotha](http://www.kotha.net/bfi/)

Compiling
---------

As the standard Brainfuck symbols are invalid preprocessor tokens they have been mapped to the following characters. Interactive input is also disabled as this is unsupported by the C preprocessor.

* `>` => `R`
* `<` => `L`
* `+` => `U`
* `-` => `D`
* `.` => `O`
* `[` => `F`
* `]` => `B`

Then a program can be compiled as so:

* `cpp MAIN.h -D STDIN=(U,U,U,U,U,U,U,U,U,U,F,R,U,U,U,U,U,U,U,R,U,U,U,U,U,U,U,U,U,U,R,U,U,U,R,U,L,L,L,L,D,B,R,U,U,O,R,U,O,U,U,U,U,U,U,U,O,O,U,U,U,O,R,U,U,O,L,L,U,U,U,U,U,U,U,U,U,U,U,U,U,U,U,O,R,O,U,U,U,O,D,D,D,D,D,D,O,D,D,D,D,D,D,D,D,O,R,U,O)`

Wait for about 15 seconds then the result should appear.

* `'H' 'e' 'l' 'l' 'o' ' ' 'W' 'o' 'r' 'l' 'd' '!'`

Currently the maximum recursion depth is set to around `1000` and the data array size around `100`. These can be easily extended but for now, as a general rule of thumb computations exceeding `1000` steps may not run.


About
-----

Programming in the C Preprocessor is an odd experience. It is like using a purely functional programming language with a single type - _The Token_ - and a single operation on that type - _Token pasting_. This means no arithmetic, concept of numbers or data structures. In fact the language of the C Preprocessor is _so pure_ that it does everything in it's power to disable that most dangerous of computational patterns - _recursion_.

__Token Pasting__

Luckily _The Token_ and _Token Pasting_ can be used to make surprisingly complex things. For example basic boolean logic can be easily implement via the following:

```c
#define AND(X, Y) AND_##X##_##Y
#define AND_0_0 0
#define AND_0_1 0
#define AND_1_0 0
#define AND_1_1 1
```

Ultimately just this should be enough for turing completeness. Using these truth tables one could theoretically make a binary computer much like has been done in systems such Conway's Game of Life or even Minecraft. After encountering a number of issues in my normal approach I seriously considered this approach for a short while, having done a course on computer architecture, and with some experience in control circuits. In the end the number of unforeseen  limitations scared me off - and even having a working 32-bit computer would still be a long way from Brainfuck.

Luckily arithmetic, logic and a whole bunch of other things can also be defined using just recursion and the ordering of the natural numbers.

```c
#define INC(X) JOIN(INC_, X)
#define INC_0 1
#define INC_1 2
#define INC_2 3
...

#define DEC(X) JOIN(DEC_, X)
#define DEC_1 0
#define DEC_2 1
#define DEC_3 2
...

// pseudocode
#define ADD(X, Y) if Y == 0 then X else ADD(INC(X), DEC(Y))
```

But for the above to work we need some concept of conditionals and recursion, both unsupported in the C Preprocessor. Luckily we can roll our own.

__Conditionals__

To implement conditionals we can again use token pasting. The method is surprisingly straight forward.

```c
#define IF_ELSE(C, T, E) JOIN(IF_ELSE_, C)(T, E)
#define IF_ELSE_0(T, E) E
#define IF_ELSE_1(T, E) T

#define IF(C, T) IF_ELSE(C, T, )
```

But unfortunately it has one big downside. That the C preprocessor will fully evaluate both sides of a conditional before picking which side to apply. While this might be just a slight annoyance for fairly simple expressions and linear programming, it becomes absolutely disastrous when combined with looping or recursion.

The reason is that at the point where the recursion should stop, the computation will branch into one state where the recursion has stopped as normal, and one branch where the recursion is still continuing. This continuation branch loops until there is an error or the maximum recursion depth is exceeded.

My initial version of the Brainfuck interpreter exhibited this behavior. As you would expect it was EXTREMELY slow and used HUGE amounts of memory. It could not perform more than a couple of steps, and had an odd paradoxical relationship to turing completeness.

When we talk about turing completeness we usually take liberties over the specification of an "infinite tape". Due to physical limitations no machine can ever have an infinite tape. So we say that if the tape is clearly extendible to the needs of whatever realistic computation is taking place, it is more of less infinite, and the machine is turing complete.

My Brainfuck interpreter was then in an odd position. It would terminate if and only if the tape was finite. By all practicalities it had to be finite - but this was not the definition of turing completeness. Of course it also did computation in no sensible way known to man. It first evaluated the tree of all possible computations of a given program, branching at conditionals, and only once this tree was complete to the maximum stack depth would it begin searching that tree for the path actually taken.

Eventually I did solve this issue, which gave me a basic recursion primitive I could use across the system without fear, but the in between result was certainly an interesting machine.

__Recursion__

There are two existing techniques to achieve recursion in the C Preprocessor. The first technique, used by the Boost preprocessor library and many others and is to just enumerate a number of identical recursive functions, each calling the next one down the stack.

```c
#define REPEAT(COND, UPDATE, X) REPEAT0(COND, UPDATE, X)
#define REPEAT0(COND, UPDATE, X) IF(COND(X), REPEAT1(COND, UPDATE, UPDATE(X)))
#define REPEAT1(COND, UPDATE, X) IF(COND(X), REPEAT2(COND, UPDATE, UPDATE(X)))
#define REPEAT2(COND, UPDATE, X) IF(COND(X), REPEAT3(COND, UPDATE, UPDATE(X)))
#define REPEAT3(COND, UPDATE, X) IF(COND(X), REPEAT4(COND, UPDATE, UPDATE(X)))
#define REPEAT4(COND, UPDATE, X) IF(COND(X), REPEAT5(COND, UPDATE, UPDATE(X)))
...
```

There are two problems with this approach. The first is that a number of functions must be created as deep as the stack. The second is that the `COND` or `UPDATE` functions must not contain in themselves any reference to the `REPEAT` macro. Even trivial loops such as `while(X != 10) { X += 2; }` cannot be expressed via the above method because `X += 2` requires addition and `X != 10` requires subtraction - both of which may be defined in terms of `REPEAT`.

Another method is explained by [pfultz](https://github.com/pfultz2/Cloak/wiki/Is-the-C-preprocessor-Turing-complete%3F) which removes several of these issues. I attempted his implementation but encountered several issues of my own. In general the semantics of this particular behavior of delayed evaluation were too complicated to get my head around and unify with the rest of my system. It also exhibited the issues with conditionals explained above - but because there was no finite stack depth it tended toward infinite recursion.

In the end I implemented a combination of the two. The recursion depth `$` is explicitly passed in to allow for recursive functions to call other recursive functions, and a more general pattern is used to capture all kinds of recursive functions.

```c
// $ - Recursion Depth
// C - Conditional Function
// M - Side Effect
// U - Update Function
// E - Function Upon termination
// X - value to act upon
// Usage:
//
//  #define RCOND($, X) BOOL(X)
//  #define RMACRO($, X) X
//  #define RUPDATE($, X) SUB($, X, 2)
//  #define RFINALLY($, X) DONE
//  #define RTEST($, X) JOIN(RECR_D, $)(INC($), RCOND, RMACRO, RUPDATE, RFINALLY, X)
//
//  RTEST($, 10) => 10 8 6 4 2 DONE
//
```

The core recursive function requires two macros to avoid some issues with `JOIN` and also to allow for "kicking" of looped recursion when the conditional fails. This is to stop the unwanted behavior of conditionals explained above.

```c

// On failed condition created undefined token to halt recursion
#define KICK(C, $) IF_ELSE(C, INC($), KICKED)

#define RECR_A0($, C, M, U, E, X)   IF_ELSE( C($, X), M($, X) JOIN(RECR_D, $)(KICK(C($, X), $), C, M, U, E, U($, X)), E($, X) )
#define RECR_A1($, C, M, U, E, X)   IF_ELSE( C($, X), M($, X) JOIN(RECR_D, $)(KICK(C($, X), $), C, M, U, E, U($, X)), E($, X) )
...

#define RECR_D0($, C, M, U, E, X)   JOIN(RECR_A, $)(INC($), C, M, U, E, X)
#define RECR_D1($, C, M, U, E, X)   JOIN(RECR_A, $)(INC($), C, M, U, E, X)
...
```

While this still required enumeration to maximum stack depth, the contents of each expression are the same, and it does provide general purpose reuse for many types of iteration.

But one final problem with this recursion is that is only allows manipulation of a single data value `X`. To compute on more than one value requires a data structure...

__Lists__

For lists I used delayed evaluation and variable argument macros to create a functional list of tokens.

```c
#define EVAL(...) __VA_ARGS__

#define LIST(...) (__VA_ARGS__)
#define LIST_HEAD(X, ...) X
#define LIST_TAIL(X, ...) (__VA_ARGS__)

#define UNCURRY(M, ...) M(__VA_ARGS__)
#define CURRY(M, L) EVAL(M L)

#define HEAD(L) CURRY(LIST_HEAD, L)
#define TAIL(L) CURRY(LIST_TAIL, L)
...
```

Lists could then be created using round brackets and updated with the functions I had specified.

```c
// 1
HEAD( (1, 2, 7, 23) )

// (1, 99, 12)
TAIL( (3, 1, 99, 12) )

// (5, 1, 2, 3)
CONS( 5, (1, 2, 3) )
```

I then used the recursion primative to build many more useful list operations. Lists provided useful for all my data structures including arrays and state-tuples.

__Brainfuck__

Finally I could put all of the above together to define a program which computed brainfuck. This is a recursion across a brainfuck state specified as `(Instrction Pointer, Data Pointer, Instruction Array, Data Array)`.

Symbols are extracted using the `NTH` item of the instruction array. Then are then pattern matched using `JOIN` against macros which perform the correct behaviour for that instruction. The state is updated correctly and termination conditions are checked. A conditional side effect is performed if the ouput symbol is seen.

For more information see the source code...


Turing Machine
==============

I also have included code for a turing machine. Unfortunately the setup is a little more laborious as state transitions, starting state, and initial tape state must all be defined. This machine currently does not treat all edge cases and will terminate only when the head goes off the right side of the tape. All transitions must be defined. I will be making updates to improve these conditions soon.

The initial starting state is defined using `Q` for example `-D Q=s0`

The initial tape state is defined using `T`, for example `-D T=(0,0,1,1,0,1,0,0)` 

Transitions are defined using the form `-D T_A_R=(B,W,D)` where:

* `A` - Current State
* `B` - Next State
* `R <- {0, 1}` - Binary Tape Read
* `W <- {0, 1}` - Binary Tape Write
* `D <- {l, R}` - Tape Head Direction

For example `-D T_s0_0=(s1,1,R)`.

It is important to ensure all valid transitions are defined and also important to ensuring there are no spaces in the tuple - otherwise it will not parse correctly on the command line.

Putting this altogether we can define a machine which alternate writing `0` and `1` to the tape as follows:

* `cpp MAIN_TM.h -D T=(0,0,1,0,1,1,0,0,1) -D Q=s0 -D T_s0_0=(s1,0,R) -D T_s0_1=(s1,0,R) -D T_s1_0=(s0,1,R) -D T_s1_1=(s0,1,R)`

This should output:

* `( (0, 1, 0, 1, 0, 1, 0, 1, 0), s1, 9 )`

Which shows the final tape state, the final machine state and the final tape head position.


FizzBuzz
========

I felt it was time to hop on that bandwagon. Perhaps the simplest example of use.

To compile:

* `cpp MAIN_FZBZ.h`

Should output:

* `1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz Buzz 26 Fizz 28 29 FizzBuzz 31 32 Fizz 34 Buzz Fizz 37 38 Fizz Buzz 41 Fizz 43 44 FizzBuzz 46 47 Fizz 49 Buzz Fizz 52 53 Fizz Buzz 56 Fizz 58 59 FizzBuzz 61 62 Fizz 64 Buzz Fizz 67 68 Fizz Buzz 71 Fizz 73 74 FizzBuzz 76 77 Fizz 79 Buzz Fizz 82 83 Fizz Buzz 86 Fizz 88 89 FizzBuzz 91 92 Fizz 94 Buzz Fizz 97 98 Fizz Buzz`

Library
=======

All code is avaliable under BSD3 and contributions toward the code as a library are welcome. I mainly built the functionality required for brainfuck but (clearly) many more things are possible and any missing peices are more than welcome.
