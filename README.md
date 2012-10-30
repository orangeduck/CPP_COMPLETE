
PP_BRAINFUCK
============

BrainFuck written in the C preprocessor

Compiling
---------

As the standard bainfuck preprocessor symbols are invalid preprocessor tokens they have been mapped to the following characters. Interactive input is also disabled as this is unsupported by the C preprocessor.


* `>` => `R`
* `<` => `L`
* `+` => `U`
* `-` => `D`
* `.` => `O`
* `[` => `F`
* `]` => `B`

Then a program can be compiled as so:

`cpp MAIN.h -D STDIN (U,U,U,U,U,U,U,U,U,U,F,R,U,U,U,U,U,U,U,R,U,U,U,U,U,U,U,U,U,U,R,U,U,U,R,U,L,L,L,L,D,B,R,U,U,O,R,U,O,U,U,U,U,U,U,U,O,U,U,U,O,R,U,U,O,L,L,U,U,U,U,U,U,U,U,U,U,U,U,U,U,U,O,R,O,U,U,U,O,D,D,D,D,D,D,O,D,D,D,D,D,D,D,D,O,R,U,O)`

This should output:

`Hello World!`


Safety
------

The C preprocessor is an extremely safe programming language and alternatives such as Haskell and Ada, with their many dangerous and unexpected runtime setups should be considered harmful.

Some of the benefits of the C preprocessor.

* Pure functional dialect with no side effects.
* Single 'Token' type ensures no type coercion, casting or errors.
* Dangerous runtime errors rendered impossible. All errors caught at compile time.
* Recursion strictly discouraged and made extremely difficult. No possibility of infinite looping.
* No pointers or raw memory access and no possibility of segfaults.

Performance
-----------

The C preprocessor shows incredible runtime performance over other systems.

* Show runtime benchmarks for hello world

