#include "PP.h"

/* Recursion */

#define PP_R1C($, X) PP_BOOL(X)
#define PP_R1M($, X) X
#define PP_R1U($, X) PP_SUB($, X, 3)
#define PP_R1E($, X) DONE
PP_RECR_D0($0, PP_R1C, PP_R1M, PP_R1U, PP_R1E, 8)

#define PP_R2C($, X) PP_LT($, X, 5)
#define PP_R2M($, X) X
#define PP_R2U($, X) PP_INC(X)
#define PP_R2E($, X) DONE
PP_RECR_D0($0, PP_R2C, PP_R2M, PP_R2U, PP_R2E, 0)

/* Maths */

PP_SUB($0, 2, 4)
PP_SUB($0, 2, 3)
PP_SUB($0, 2, 2)
PP_SUB($0, 2, 1)
PP_SUB($0, 2, 0)
PP_SUB($0, 5, 3)
PP_ADD($0, 2, 3)
PP_ADD($0, PP_ADD($0, 2, 3), 2)
PP_ADD($0, PP_ADD($0, 2, 3), 2)

/* logic */

PP_GT($0, 4, 3)
PP_GT($0, 3, 3)
PP_GT($0, 2, 3)
PP_GT($0, 1, 3)

PP_LT($0, 4, 3)
PP_LT($0, 3, 3)
PP_LT($0, 2, 3)
PP_LT($0, 1, 3)
PP_LT($0, 2, 2)

PP_EQ($0, PP_GT($0, 5, 4), 1)
PP_EQ($0, PP_GT($0, 3, 4), 0)
PP_EQ($0, PP_GT($0, 1, 1), 0)
PP_EQ($0, PP_GT($0, 2, 8), 0)

PP_EQ($0, PP_LT($0, 5, 4), 0)
PP_EQ($0, PP_LT($0, 3, 4), 1)
PP_EQ($0, PP_LT($0, 1, 1), 0)
PP_EQ($0, PP_LT($0, 2, 8), 1)

PP_EQ($0, PP_GE($0, 5, 4), 1)
PP_EQ($0, PP_GE($0, 3, 4), 0)
PP_EQ($0, PP_GE($0, 1, 1), 1)
PP_EQ($0, PP_GE($0, 2, 8), 0)

PP_EQ($0, PP_LE($0, 5, 4), 0)
PP_EQ($0, PP_LE($0, 3, 4), 1)
PP_EQ($0, PP_LE($0, 1, 1), 1)
PP_EQ($0, PP_LE($0, 2, 8), 1)

PP_EQ($0, PP_EQ($0, 5, 4), 0)
PP_EQ($0, PP_EQ($0, 3, 4), 0)
PP_EQ($0, PP_EQ($0, 1, 1), 1)
PP_EQ($0, PP_EQ($0, 2, 8), 0)

PP_EQ($0, PP_ADD($0, 2, 3), 5)

/* Lists */

PP_NTH($0, (3, 7, 1, 6, 2), 3)
PP_NTH($0, (3, 7, 1, 6, 2), 5)

PP_LEN($0, (3, 2, 1, 8))
PP_LEN($0, (2, 1))

PP_HEAD((1,2))
PP_TAIL((3,1))

PP_NTH($0, (0,1,1,0), 5)
PP_NTH($0, (1,1,0,1), 4)
PP_NTH($0, (1,0,1,0), 3)
PP_NTH($0, (1,0,1,0), 2)
PP_NTH($0, (0,1,0,1), 1)
PP_NTH($0, (0,1,0,1), 0)

PP_SND(((), 2, 2))
PP_TRD(((), 2, 2))

PP_CONS(5, (1, 2, 3))
PP_CONCAT((1, 2), (7))
PP_CONCAT((), (7, 8, 9))
PP_CONCAT((7, 8, 9), ())

PP_LEN($0, ())
PP_LEN($0, (1))
PP_LEN($0, (2, 1, 4, 5))

PP_ISEMPTY( () )
PP_ISEMPTY( (0) )
PP_ISEMPTY( (1) )
PP_ISEMPTY( (0, 0) )
PP_ISEMPTY( (0, 1) )
PP_ISEMPTY( (1, 1) )

PP_TAKE( $0, (1,2,3,4), 4 )
PP_TAKE( $0, (1,2,3,4), 3 )
PP_TAKE( $0, (1,2,3,4), 2 )
PP_TAKE( $0, (1,2,3,4), 1 )
PP_TAKE( $0, (1,2,3,4), 0 )
PP_DROP( $0, (1,2,3,4), 4 )
PP_DROP( $0, (1,2,3,4), 3 )
PP_DROP( $0, (1,2,3,4), 2 )
PP_DROP( $0, (1,2,3,4), 1 )
PP_DROP( $0, (1,2,3,4), 0 )

/* Brainfuck */

#include "PP_BRAINFUCK.h"

PP_BF_INSTR($0, (0, 0, (R,U,U), (0,0,0)))
PP_BF_INSTR($0, (1, 0, (R,U,U), (0,0,0)))
PP_BF_INSTR($0, (2, 0, (R,U,U), (0,0,0)))

PP_BF_DATA($0, (0, 0, (R,U,U), (5,8,9)))
PP_BF_DATA($0, (0, 1, (R,U,U), (0,2,4)))
PP_BF_DATA($0, (0, 2, (R,U,U), (3,1,7)))

PP_BF_COND($0, (0, 0, (), (0,0,0)))
PP_BF_COND($0, (2, 0, (R,U,U), (0,0,0)))
PP_BF_COND($0, (3, 0, (R,U,U), (0,0,0)))

PP_BF_MACRO($0, (0, 0, (R,U,U,O,D), (5,0,0)))
PP_BF_MACRO($0, (1, 0, (R,U,U,O,D), (5,0,0)))
PP_BF_MACRO($0, (2, 0, (R,U,U,O,D), (5,0,0)))
PP_BF_MACRO($0, (3, 0, (R,U,U,O,D), (111,0,0)))
PP_BF_MACRO($0, (3, 0, (R,U,U,O,D), (104,0,0)))
PP_BF_MACRO($0, (3, 0, (R,U,U,O,D), (105,8,0)))
PP_BF_MACRO($0, (4, 0, (R,U,U,O,D), (5,0,0)))

PP_BF_UPDATE($0, (1, 0, (U,R,U,U,O,D), (0,0,0)) ) // Left
PP_BF_UPDATE($0, (0, 1, (L,U,U,O,D), (0,0,0)) ) // Right
PP_BF_UPDATE($0, (0, 1, (O,U,U,O,D), (0,0,0)) ) // Output

PP_BF_UPDATE($0, (0, 1, (U,U,U,O,D), (5,1,7)) ) // Up
PP_BF_UPDATE($0, (0, 1, (D,U,U,O,D), (3,4,8)) ) // Down

PP_BF_UPDATE($0, (0, 0, (F,U,U,B,D), (0,1,7)) ) // Forward
PP_BF_UPDATE($0, (0, 0, (F,D,B,U,U), (1,1,7)) ) // Forward
PP_BF_UPDATE($0, (3, 0, (F,U,U,B,D), (0,4,8)) ) // Back
PP_BF_UPDATE($0, (3, 0, (F,U,U,B,D), (1,4,8)) ) // Back
PP_BF_UPDATE($0, (4, 0, (R,F,U,U,B,D), (0,4,8)) ) // Back
PP_BF_UPDATE($0, (4, 0, (R,F,U,U,B,D), (1,4,8)) ) // Back

//PP_BRAINFUCK( () )
//PP_BRAINFUCK( (R,R,L) )
//PP_BRAINFUCK( (O,O,R,O) )
//PP_BRAINFUCK( (O,U,O,U,O) )
//PP_BRAINFUCK( (U,U,F,R,U,U,L,D,B,R,O) )
//PP_BRAINFUCK( (U,U,U,U,U,U,U,U,O,F,R,U,U,U,U,U,U,U,U,L,D,B,R,U,O) )
//PP_BRAINFUCK( (U,U,U,U,U,U,U,U,U,U,F,R,U,U,U,U,U,U,U,R,U,U,U,U,U,U,U,U,U,U,R,U,U,U,R,U,L,L,L,L,D,B,R,U,U,O,R,U,O,U,U,U,U,U,U,U,O,U,U,U,O,R,U,U,O,L,L,U,U,U,U,U,U,U,U,U,U,U,U,U,U,U,O,R,O,U,U,U,O,D,D,D,D,D,D,O,D,D,D,D,D,D,D,D,O,R,U,O) )

/* Turing Machine */

#include "PP_TURING.h"

PP_TURING_RECR_C($0, ((0,0,0,0), 0, 0) )
PP_TURING_RECR_C($0, ((0,0,0,0), 0, 1) )
PP_TURING_RECR_C($0, ((0,0,0,0), 0, 2) )
PP_TURING_RECR_C($0, ((0,0,0,0), 0, 3) )
PP_TURING_RECR_C($0, ((0,0,0,0), 0, 4) )
PP_TURING_RECR_C($0, ((0,0,0,0), 0, 5) )

#define T_s0_0 (s1, 1, R)
#define T_s0_1 (s0, 1, R)
#define T_s1_0 (s1, 1, R)
#define T_s1_1 (s0, 1, R)

PP_TM_STATE_U($0, ((0,0,1,1,0,1), s0, 1))
PP_TM_STATE_U($0, ((0,0,1,1,0,1), s0, 2))
PP_TM_STATE_U($0, ((0,0,1,1,0,1), s0, 3))
PP_TM_STATE_U($0, ((0,0,1,1,0,1), s0, 4))
PP_TM_STATE_U($0, ((0,0,1,1,0,1), s0, 5))
PP_TM_STATE_U($0, ((0,0,1,1,0,1), s0, 6))
PP_TM_STATE_U($0, ((0,0,1,1,0,1), s0, 7))

PP_TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 1))
PP_TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 2))
PP_TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 3))
PP_TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 4))
PP_TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 5))
PP_TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 6))
PP_TM_HEAD_U($0, ((0,0,1,1,0,1), s0, 7))

PP_TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 1))
PP_TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 2))
PP_TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 3))
PP_TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 4))
PP_TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 5))
//PP_TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 6))
//PP_TM_TAPE_U($0, ((0,0,1,1,0,1), s0, 7))

PP_TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 2))
PP_TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 3))
PP_TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 4))
PP_TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 5))
//PP_TURING_RECR_U($0, ((0,0,1,1,0,1), s0, 6))



PP_TM_TAPE_SET($0, (0,0,1,1,0,1), 0, 1)
PP_TM_TAPE_SET($0, (0,0,1,1,0,1), 1, 1)
PP_TM_TAPE_SET($0, (0,0,1,1,0,1), 2, 0)
PP_TM_TAPE_SET($0, (0,0,1,1,0,1), 3, 1)

//PP_TURING((), s0)
//PP_TURING((1), s0)
//PP_TURING((0,1), s0)
//PP_TURING((0,0,1,1,0,1), s0)

