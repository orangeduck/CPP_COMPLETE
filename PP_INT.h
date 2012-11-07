#ifndef PP_INT_H
#define PP_INT_H

#include "PP_CORE.h"
#include "PP_INC.h"
#include "PP_DEC.h"
#include "PP_COND.h"
#include "PP_RECR.h"
#include "PP_LIST.h"

#define PP_ADD_C($, X) PP_BOOL(PP_SND(X))
#define PP_ADD_M($, X) 
#define PP_ADD_U($, X) (PP_INC(PP_FST(X)), PP_DEC(PP_SND(X)))
#define PP_ADD_E($, X) PP_FST(X)

#define PP_SUB_C($, X) PP_BOOL(PP_SND(X))
#define PP_SUB_M($, X) 
#define PP_SUB_U($, X) (PP_DEC(PP_FST(X)), PP_DEC(PP_SND(X)))
#define PP_SUB_E($, X) PP_FST(X)

#define PP_ADD($, X, Y) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_ADD_C, PP_ADD_M, PP_ADD_U, PP_ADD_E, (X, Y))
#define PP_SUB($, X, Y) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_SUB_C, PP_SUB_M, PP_SUB_U, PP_SUB_E, (X, Y))

#define PP_GT($, X, Y) PP_BOOL(PP_SUB($, X, Y))
#define PP_LT($, X, Y) PP_BOOL(PP_SUB($, Y, X))
#define PP_LE($, X, Y) PP_NOT(PP_GT($, X, Y))
#define PP_GE($, X, Y) PP_NOT(PP_LT($, X, Y))
#define PP_EQ($, X, Y) PP_AND(PP_NOT(PP_LT($, X, Y)), PP_NOT(PP_LT($, Y, X)))
#define PP_NEQ($, X, Y) PP_NOT(PP_EQ($, X, Y))

#endif