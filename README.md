
PP_BRAINFUCK
============

BrainFuck written in the C preprocessor

WARNING
-------

This implementation of brainfuck is EXTREMELY slow and takes HUGE amounts of memory. The reason for this is that it does not do computation as we commonly think of it, but rather evaluates all possible computation paths to their termination. It then parses this computation tree and folds it into the actual computation path for the program. This forced evaluation includes the continuation of loops when their conditional fails. It unfolds these loops up to the maximum-recursion-depth.

This means the execution speed grows exponentially (or more) with the size of the input. An input of around 10 characters can take half an hour to an hour. An input of any more will not compute as memory will be exceeded.

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

For now, square brackets are also unmatched but this is certainly possible to add.

Then a program can be compiled as so:

* `cpp MAIN.h -D STDIN=(U,U,F,R,U,U,L,D,B,R,O)`

Wait for about 15 minutes. Then it should output the result:

* `[EOT]`

