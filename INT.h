#ifndef INT_H
#define INT_H

#include "CORE.h"
#include "INC.h"
#include "DEC.h"
#include "COND.h"
#include "RECR.h"
#include "LIST.h"

#define ADD_C($, X) BOOL(SND(X))
#define ADD_M($, X) 
#define ADD_U($, X) (INC(FST(X)), DEC(SND(X)))
#define ADD_E($, X) FST(X)

#define SUB_C($, X) BOOL(SND(X))
#define SUB_M($, X) 
#define SUB_U($, X) (DEC(FST(X)), DEC(SND(X)))
#define SUB_E($, X) FST(X)

#define ADD($, X, Y) JOIN(RECR_D, $)(INC($), ADD_C, ADD_M, ADD_U, ADD_E, (X, Y))
#define SUB($, X, Y) JOIN(RECR_D, $)(INC($), SUB_C, SUB_M, SUB_U, SUB_E, (X, Y))

#define GT($, X, Y) BOOL(SUB($, X, Y))
#define LT($, X, Y) BOOL(SUB($, Y, X))
#define LE($, X, Y) NOT(GT($, X, Y))
#define GE($, X, Y) NOT(LT($, X, Y))
#define EQ($, X, Y) AND(NOT(LT($, X, Y)), NOT(LT($, Y, X)))
#define NEQ($, X, Y) NOT(EQ($, X, Y))

#endif