#ifndef PP_INT_H
#define PP_INT_H

#include "PP_CORE.h"
#include "PP_COND.h"
#include "PP_LOOP.h"
#include "PP_LIST.h"

#define PP_INC(X) PP_JOIN(PP_INC_, X)
#define PP_INC_0 1
#define PP_INC_1 2
#define PP_INC_2 3
#define PP_INC_3 4
#define PP_INC_4 5
#define PP_INC_5 6
#define PP_INC_6 7
#define PP_INC_7 8
#define PP_INC_8 9
#define PP_INC_9 9

#define PP_DEC(X) PP_JOIN(PP_DEC_, X)

#define PP_DEC_0 0
#define PP_DEC_1 0
#define PP_DEC_2 1
#define PP_DEC_3 2
#define PP_DEC_4 3
#define PP_DEC_5 4
#define PP_DEC_6 5
#define PP_DEC_7 6
#define PP_DEC_8 7
#define PP_DEC_9 8

#define PP_ADD_C(X) PP_BOOL(PP_SND(X))
#define PP_ADD_U(X) (PP_INC(PP_FST(X)), PP_DEC(PP_SND(X)))
#define PP_SUB_U(X) (PP_DEC(PP_FST(X)), PP_DEC(PP_SND(X)))

#define PP_ADD(X, Y) PP_FOR(PP_ADD_C, PP_EAT, PP_ADD_U, PP_FST, (X, Y))
#define PP_SUB(X, Y) PP_FOR(PP_ADD_C, PP_EAT, PP_SUB_U, PP_FST, (X, Y))

#define PP_GT(X, Y) PP_BOOL(PP_SUB(X, Y))
#define PP_LT(X, Y) PP_BOOL(PP_SUB(Y, X))
#define PP_LE(X, Y) PP_NOT(PP_GT(X, Y))
#define PP_GE(X, Y) PP_NOT(PP_LT(X, Y))
#define PP_EQ(X, Y) PP_AND(PP_NOT(PP_LT(X, Y)), PP_NOT(PP_LT(Y, X)))
#define PP_NEQ(X, Y) PP_NOT(PP_EQ(X, Y))

#endif