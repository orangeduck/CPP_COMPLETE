
BRAINFUCK
============

BrainFuck written in the C preprocessor

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

For now, square brackets are also unmatched but this is an improvement I will make soon.

Then a program can be compiled as so:

* `cpp MAIN_BF.h -D STDIN=(U,U,U,U,U,U,U,U,U,U,F,R,U,U,U,U,U,U,U,R,U,U,U,U,U,U,U,U,U,U,R,U,U,U,R,U,L,L,L,L,D,B,R,U,U,O,R,U,O,U,U,U,U,U,U,U,O,O,U,U,U,O,R,U,U,O,L,L,U,U,U,U,U,U,U,U,U,U,U,U,U,U,U,O,R,O,U,U,U,O,D,D,D,D,D,D,O,D,D,D,D,D,D,D,D,O,R,U,O)`

Wait for about 30 seconds then the result should appear.

* `'H' 'e' 'l' 'l' 'o' ' ' 'W' 'o' 'r' 'l' 'd' '!'`

