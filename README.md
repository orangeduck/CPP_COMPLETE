
BRAINFUCK
=========

What I believe is the first absolute proof that the C preprocessor is turing complete. This uses no GCC extensions and other than the rules for macro evaluation the only "features" it takes advantage of are token pasting and variable argument number macros.

The proof method is simple - a Brainfuck interpreter written in the C preprocessor.


Compiling
---------

As the standard bainfuck symbols are invalid preprocessor tokens they have been mapped to the following characters. Interactive input is also disabled as this is unsupported by the C preprocessor.

* `>` => `R`
* `<` => `L`
* `+` => `U`
* `-` => `D`
* `.` => `O`
* `[` => `F`
* `]` => `B`

For now, square brackets are also unmatched but this is a quick and easy to make improvement.

Then a program can be compiled as so:

* `cpp MAIN_BF.h -D STDIN=(U,U,U,U,U,U,U,U,U,U,F,R,U,U,U,U,U,U,U,R,U,U,U,U,U,U,U,U,U,U,R,U,U,U,R,U,L,L,L,L,D,B,R,U,U,O,R,U,O,U,U,U,U,U,U,U,O,O,U,U,U,O,R,U,U,O,L,L,U,U,U,U,U,U,U,U,U,U,U,U,U,U,U,O,R,O,U,U,U,O,D,D,D,D,D,D,O,D,D,D,D,D,D,D,D,O,R,U,O)`

Wait for about 30 seconds then the result should appear.

* `'H' 'e' 'l' 'l' 'o' ' ' 'W' 'o' 'r' 'l' 'd' '!'`


Library
-------

All work here can be considered licensed under BSD3 and you are welcome to use any of the functionality in your own applications if you wish. To implement brainfuck I provide functionality for the following basic constructs:

* Recursion
* Conditionals
* Lists
* Integers
* Characters/Strings
  

Turing Machine
--------------

I am also working on a Turing Machine in the CPP. This is coming soon...

