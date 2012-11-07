#include "PP.h"

/* Recursion */

#define PP_RBOOL($, X) PP_BOOL(X)
#define PP_REVAL($, X) X
#define PP_RDEC($, X) PP_SUB($, X, 3)
#define PP_RDONE($, X) DONE
PP_RECR_D0($0, PP_RBOOL, PP_REVAL, PP_RDEC, PP_RDONE, 8)

#define PP_RLT($, X) PP_LT($, X, 5)
#define PP_RINC($, X) PP_INC(X)
#define PP_REVAL2($, X) X
PP_RECR_D0($0, PP_RLT, PP_REVAL2, PP_RINC, PP_RDONE, 0)

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

PP_LEN($0, (3, 2, 1, 8))
PP_LEN($0, (2, 1))

PP_HEAD((1,2))
PP_TAIL((3,1))

PP_SND(((), 2, 2))
PP_TRD(((), 2, 2))

PP_CONS(5, (1, 2, 3))
PP_CONCAT((1, 2), (7))

PP_LEN($0, ())
PP_LEN($0, (1))
PP_LEN($0, (2, 1, 4, 5))

PP_ISEMPTY( () )
PP_ISEMPTY( (0) )
PP_ISEMPTY( (1) )
PP_ISEMPTY( (0, 0) )
PP_ISEMPTY( (0, 1) )
PP_ISEMPTY( (1, 1) )
