
BRAINFUCK
=========

A Brainfuck interpreter written in the C preprocessor.

There has been much speculation on the turing completeness of the C Preprocessor, but I believe this is the first demonstrative proof that the C preprocessor _is_ turing complete. This uses no GCC extensions and other than the rules for macro evaluation the only "features" it takes advantage of are token pasting and variable argument macros.

Thanks to [pfultz](https://github.com/pfultz2/Cloak/wiki/Is-the-C-preprocessor-Turing-complete%3F) and the many others for their contributions and ideas on recursion in the C preprocessor.

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

Wait for about 30 seconds then the result should appear.

* `'H' 'e' 'l' 'l' 'o' ' ' 'W' 'o' 'r' 'l' 'd' '!'`


About
-----

Programming in the C Preprocessor is an odd experience. It is like using a purely functional programming language with a single type - _The Token_ - and a single operation on that type - _Token pasting_. This means no arithmetic, concept of numbers or data structures. In fact the language of the C Preprocessor is _so pure_ that it does everything in it's power to disable that most dangerous of computational patterns - _recursion_.

__Token Pasting__

Luckily _The Token_ and _Token Pasting_ can be used to make surprisingly complex things. For example basic boolean logic can be easily implement via the following:

```c
#define AND(X, Y) AND_##Y##_##Z
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

It would be nice if the above were how easy it was, but it is just pseudocode. For it to work we have to roll our own conditional expressions and recursion.

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

There are two problems with this approach. The first is that a number of functions must be created as deep as the stack. The second is that the `COND` or `UPDATE` functions must not contain in themselves any reference to the `REPEAT` macro. Even trivial loops such as `while(X != 10) { X += 2; }` cannot be expressed via the above method because `X += 2` requires addition and `X != 10` requires subtraction.

Another method is explained by [pfultz](https://github.com/pfultz2/Cloak/wiki/Is-the-C-preprocessor-Turing-complete%3F) which removes several of these issues. I attempted his implementation but encountered several issues of my own. In general the semantics of this particular behavior of delayed evaluation were too complicated to get my head around and unify with the rest of my system.

In the end I implemented a combination of the two. The recursion depth `$` is explicitly passed in to allow for recursive functions to call other recursive functions, and a more general pattern is used to capture all kinds of recursive functions.

```c
// $ - Recursion Depth
// C - Conditional Function
// M - Side Effect
// U - Update Function
// E - Function Upon termination
// X - value to act on
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

The core recursive functions requires two macros to avoid some issues with `JOIN` and also to allow for "kicking" of looped recursion when the conditional fails. This is to stop the unwanted behavior of conditionals explained above.

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

While this still required enumeration two recursive macros the contents are the same, and it does provide general purpose reuse for many types of iteration. One issue with this recursion is that is only allows manipulation of a single data value `X`. To compute on more than one value then requires a data structure...

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

I then used the recursion primative to build many more useful list operations. Lists provided useful for all my data structures including arrays and state-tuples. From this point on programming the Brainfuck interpreter was fairly straight forward.


Library
-------

All code is avaliable under BSD3 and contributions toward the code as a library are welcome. I mainly built the functionality required for brainfuck but (clearly) many more things are possible and any missing peices are more than welcome.
