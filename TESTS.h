#include "PP.h"

PP_ADD(2,3)

PP_ADD(PP_ADD(2, 3), 2)

PP_NTH((3, 7, 1, 6, 2), 2)

/*
PP_EQ(PP_GT(5, 4), 1)
PP_EQ(PP_GT(3, 4), 0)
PP_EQ(PP_GT(1, 1), 0)
PP_EQ(PP_GT(2, 8), 0)

PP_EQ(PP_LT(5, 4), 0)
PP_EQ(PP_LT(3, 4), 1)
PP_EQ(PP_LT(1, 1), 0)
PP_EQ(PP_LT(2, 8), 1)

PP_EQ(PP_GE(5, 4), 1)
PP_EQ(PP_GE(3, 4), 0)
PP_EQ(PP_GE(1, 1), 1)
PP_EQ(PP_GE(2, 8), 0)

PP_EQ(PP_LE(5, 4), 0)
PP_EQ(PP_LE(3, 4), 1)
PP_EQ(PP_LE(1, 1), 1)
PP_EQ(PP_LE(2, 8), 1)

PP_EQ(PP_EQ(5, 4), 0)
PP_EQ(PP_EQ(3, 4), 0)
PP_EQ(PP_EQ(1, 1), 1)
PP_EQ(PP_EQ(2, 8), 0)

PP_EQ(PP_ADD(2, 3), 5)

PP_ADD(PP_ADD(2, 3), 2)

PP_HEAD((1,2))
PP_TAIL((3,1))

PP_SND(((), 2, 2))
PP_TRD(((), 2, 2))
PP_LT(2, 2)

PP_CONS(5, (1, 2, 3))
PP_CONCAT((1, 2), (7))


#define PP_LT_5(X) PP_LT(X, 5)
PP_FOR(PP_LT_5, PP_EVAL, PP_INC, PP_EAT, 0)

PP_LEN(())
PP_LEN((1))
PP_LEN((2, 1, 4, 5))

PP_ISEMPTY( () )
PP_ISEMPTY( (0) )
PP_ISEMPTY( (1) )
PP_ISEMPTY( (0, 0) )
PP_ISEMPTY( (0, 1) )
PP_ISEMPTY( (1, 1) )
*/
