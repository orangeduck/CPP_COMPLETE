#include "COMPLETE.h"

/* Recursion */

#define R1C($, X) BOOL(X)
#define R1M($, X) X
#define R1U($, X) SUB($, X, 3)
#define R1E($, X) DONE
RECR_D0($0, R1C, R1M, R1U, R1E, 8)

#define R2C($, X) LT($, X, 5)
#define R2M($, X) X
#define R2U($, X) INC(X)
#define R2E($, X) DONE
RECR_D0($0, R2C, R2M, R2U, R2E, 0)

/* Maths */

SUB($0, 2, 4)
SUB($0, 2, 3)
SUB($0, 2, 2)
SUB($0, 2, 1)
SUB($0, 2, 0)
SUB($0, 5, 3)
ADD($0, 2, 3)
ADD($0, ADD($0, 2, 3), 2)
ADD($0, ADD($0, 2, 3), 2)

/* logic */

GT($0, 4, 3)
GT($0, 3, 3)
GT($0, 2, 3)
GT($0, 1, 3)

LT($0, 4, 3)
LT($0, 3, 3)
LT($0, 2, 3)
LT($0, 1, 3)
LT($0, 2, 2)

EQ($0, GT($0, 5, 4), 1)
EQ($0, GT($0, 3, 4), 0)
EQ($0, GT($0, 1, 1), 0)
EQ($0, GT($0, 2, 8), 0)

EQ($0, LT($0, 5, 4), 0)
EQ($0, LT($0, 3, 4), 1)
EQ($0, LT($0, 1, 1), 0)
EQ($0, LT($0, 2, 8), 1)

EQ($0, GE($0, 5, 4), 1)
EQ($0, GE($0, 3, 4), 0)
EQ($0, GE($0, 1, 1), 1)
EQ($0, GE($0, 2, 8), 0)

EQ($0, LE($0, 5, 4), 0)
EQ($0, LE($0, 3, 4), 1)
EQ($0, LE($0, 1, 1), 1)
EQ($0, LE($0, 2, 8), 1)

EQ($0, EQ($0, 5, 4), 0)
EQ($0, EQ($0, 3, 4), 0)
EQ($0, EQ($0, 1, 1), 1)
EQ($0, EQ($0, 2, 8), 0)

EQ($0, ADD($0, 2, 3), 5)

/* Lists */

NTH($0, (3, 7, 1, 6, 2), 3)
NTH($0, (3, 7, 1, 6, 2), 5)

LEN($0, (3, 2, 1, 8))
LEN($0, (2, 1))

HEAD((1,2))
TAIL((3,1))

NTH($0, (0,1,1,0), 5)
NTH($0, (1,1,0,1), 4)
NTH($0, (1,0,1,0), 3)
NTH($0, (1,0,1,0), 2)
NTH($0, (0,1,0,1), 1)
NTH($0, (0,1,0,1), 0)

SND(((), 2, 2))
TRD(((), 2, 2))

CONS(5, (1, 2, 3))
CONCAT((1, 2), (7))
CONCAT((), (7, 8, 9))
CONCAT((7, 8, 9), ())

LEN($0, ())
LEN($0, (1))
LEN($0, (2, 1, 4, 5))

ISEMPTY( () )
ISEMPTY( (0) )
ISEMPTY( (1) )
ISEMPTY( (0, 0) )
ISEMPTY( (0, 1) )
ISEMPTY( (1, 1) )

TAKE( $0, (1,2,3,4), 4 )
TAKE( $0, (1,2,3,4), 3 )
TAKE( $0, (1,2,3,4), 2 )
TAKE( $0, (1,2,3,4), 1 )
TAKE( $0, (1,2,3,4), 0 )
DROP( $0, (1,2,3,4), 4 )
DROP( $0, (1,2,3,4), 3 )
DROP( $0, (1,2,3,4), 2 )
DROP( $0, (1,2,3,4), 1 )
DROP( $0, (1,2,3,4), 0 )

/* Brainfuck */

#include "BRAINFUCK.h"

BF_INSTR($0, (0, 0, (R,U,U), (0,0,0)))
BF_INSTR($0, (1, 0, (R,U,U), (0,0,0)))
BF_INSTR($0, (2, 0, (R,U,U), (0,0,0)))

BF_DATA($0, (0, 0, (R,U,U), (5,8,9)))
BF_DATA($0, (0, 1, (R,U,U), (0,2,4)))
BF_DATA($0, (0, 2, (R,U,U), (3,1,7)))

BF_COND($0, (0, 0, (), (0,0,0)))
BF_COND($0, (2, 0, (R,U,U), (0,0,0)))
BF_COND($0, (3, 0, (R,U,U), (0,0,0)))

BF_MACRO($0, (0, 0, (R,U,U,O,D), (5,0,0)))
BF_MACRO($0, (1, 0, (R,U,U,O,D), (5,0,0)))
BF_MACRO($0, (2, 0, (R,U,U,O,D), (5,0,0)))
BF_MACRO($0, (3, 0, (R,U,U,O,D), (111,0,0)))
BF_MACRO($0, (3, 0, (R,U,U,O,D), (104,0,0)))
BF_MACRO($0, (3, 0, (R,U,U,O,D), (105,8,0)))
BF_MACRO($0, (4, 0, (R,U,U,O,D), (5,0,0)))

BF_UPDATE($0, (1, 0, (U,R,U,U,O,D), (0,0,0)) ) // Left
BF_UPDATE($0, (0, 1, (L,U,U,O,D), (0,0,0)) ) // Right
BF_UPDATE($0, (0, 1, (O,U,U,O,D), (0,0,0)) ) // Output

BF_UPDATE($0, (0, 1, (U,U,U,O,D), (5,1,7)) ) // Up
BF_UPDATE($0, (0, 1, (D,U,U,O,D), (3,4,8)) ) // Down

BF_UPDATE($0, (0, 0, (F,U,U,B,D), (0,1,7)) ) // Forward
BF_UPDATE($0, (0, 0, (F,D,B,U,U), (1,1,7)) ) // Forward
BF_UPDATE($0, (3, 0, (F,U,U,B,D), (0,4,8)) ) // Back
BF_UPDATE($0, (3, 0, (F,U,U,B,D), (1,4,8)) ) // Back
BF_UPDATE($0, (4, 0, (R,F,U,U,B,D), (0,4,8)) ) // Back
BF_UPDATE($0, (4, 0, (R,F,U,U,B,D), (1,4,8)) ) // Back

BRAINFUCK( () )
BRAINFUCK( (R,R,L) )
BRAINFUCK( (O,O,R,O) )
BRAINFUCK( (O,U,O,U,O) )

//BRAINFUCK( (U,U,F,R,U,U,L,D,B,R,O) )
//BRAINFUCK( (U,U,U,U,U,U,U,U,O,F,R,U,U,U,U,U,U,U,U,L,D,B,R,U,O) )
//BRAINFUCK( (U,U,U,U,U,U,U,U,U,U,F,R,U,U,U,U,U,U,U,R,U,U,U,U,U,U,U,U,U,U,R,U,U,U,R,U,L,L,L,L,D,B,R,U,U,O,R,U,O,U,U,U,U,U,U,U,O,U,U,U,O,R,U,U,O,L,L,U,U,U,U,U,U,U,U,U,U,U,U,U,U,U,O,R,O,U,U,U,O,D,D,D,D,D,D,O,D,D,D,D,D,D,D,D,O,R,U,O) )

/* Turing Machine */

/*

#include "TURING.h"

TURING_RECR_C($0, ((0,0,0,0), 0, 0) )
TURING_RECR_C($0, ((0,0,0,0), 0, 1) )
TURING_RECR_C($0, ((0,0,0,0), 0, 2) )
TURING_RECR_C($0, ((0,0,0,0), 0, 3) )
TURING_RECR_C($0, ((0,0,0,0), 0, 4) )
TURING_RECR_C($0, ((0,0,0,0), 0, 5) )

#define T_s0_0 (s1, 1, R)
#define T_s0_1 (s0, 1, R)
#define T_s1_0 (s1, 1, R)
#define T_s1_1 (s0, 1, R)

TM_STATE_U($0, ((0,0,1,1,0,1), s0, 1))
TM_STATE_U($0, ((0,0,1,1,0,1), s0, 2))
TM_STATE_U($0, ((0,0,1,1,0,1), s0, 3))
TM_STATE_U($0, ((0,0,1,1,0,1), s0, 4))
TM_STATE_U($0, ((0,0,1,1,0,1), s0, 5))
TM_STATE_U($0, ((0,0,1,1,0,1), s0, 6))
TM_STATE_U($0, ((0,0,1,1,0,1), s0, 7))

TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 1))
TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 2))
TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 3))
TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 4))
TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 5))
TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 6))
TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 7))

TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 1))
TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 2))
TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 3))
TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 4))
TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 5))
//TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 6))
//TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 7))

TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 2))
TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 3))
TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 4))
TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 5))
//TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 6))



TM_TAPE_SET($0, (0,0,1,1,0,1), 0, 1)
TM_TAPE_SET($0, (0,0,1,1,0,1), 1, 1)
TM_TAPE_SET($0, (0,0,1,1,0,1), 2, 0)
TM_TAPE_SET($0, (0,0,1,1,0,1), 3, 1)

//TURING((), s0)
//TURING((1), s0)
//TURING((0,1), s0)
//TURING((0,0,1,1,0,1), s0)

*/
