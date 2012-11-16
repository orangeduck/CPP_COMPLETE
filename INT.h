#ifndef INT_H
#define INT_H

/*! Integer Operations */

#include "CORE.h"
#include "INC.h"
#include "DEC.h"
#include "COND.h"
#include "RECR.h"
#include "LIST.h"

/*! Addition */
#define ADD_C($, X) BOOL(SND(X))
#define ADD_M($, X) 
#define ADD_U($, X) (INC(FST(X)), DEC(SND(X)))
#define ADD_E($, X) FST(X)
#define ADD($, X, Y) JOIN(RECR_D, $)(INC($), ADD_C, ADD_M, ADD_U, ADD_E, (X, Y))

/*! Subtraction */
#define SUB_C($, X) BOOL(SND(X))
#define SUB_M($, X) 
#define SUB_U($, X) (DEC(FST(X)), DEC(SND(X)))
#define SUB_E($, X) FST(X)
#define SUB($, X, Y) JOIN(RECR_D, $)(INC($), SUB_C, SUB_M, SUB_U, SUB_E, (X, Y))

/*! Multiplication */
#define MUL_C($, X) BOOL(SND(X))
#define MUL_M($, X)
#define MUL_U($, X) (FST(X), DEC(SND(X)), ADD($, FST(X), TRD(X)))
#define MUL_E($, X) TRD(X)
#define MUL($, X, Y) JOIN(RECR_D, $)(INC($), MUL_C, MUL_M, MUL_U, MUL_E, (X, Y, 0))

/*! Division */
#define DIV_C($, X) GE($, FST(X), SND(X))
#define DIV_M($, X) 
#define DIV_U($, X) (SUB($, FST(X), SND(X)), SND(X), INC(TRD(X)))
#define DIV_E($, X) TRD(X)
#define DIV($, X, Y) JOIN(RECR_D, $)(INC($), DIV_C, DIV_M, DIV_U, DIV_E, (X, Y, 0))

/*! Remainder */
#define MOD_C($, X) GE($, FST(X), SND(X))
#define MOD_M($, X)
#define MOD_U($, X) (SUB($, FST(X), SND(X)), SND(X))
#define MOD_E($, X) FST(X)
#define MOD($, X, Y) JOIN(RECR_D, $)(INC($), MOD_C, MOD_M, MOD_U, MOD_E, (X, Y))

/*! Power */
#define POW_C($, X) BOOL(SND(X))
#define POW_M($, X)
#define POW_U($, X) (FST(X), DEC(SND(X)), MUL($, TRD(X), FST(X)))
#define POW_E($, X) TRD(X)
#define POW($, X, Y) JOIN(RECR_D, $)(INC($), POW_C, POW_M, POW_U, POW_E, (X, Y, 1))

/*! Ordering */
#define GT($, X, Y) BOOL(SUB($, X, Y))
#define LT($, X, Y) BOOL(SUB($, Y, X))
#define LE($, X, Y) NOT(GT($, X, Y))
#define GE($, X, Y) NOT(LT($, X, Y))
#define EQ($, X, Y) AND(NOT(LT($, X, Y)), NOT(LT($, Y, X)))
#define NEQ($, X, Y) NOT(EQ($, X, Y))

#endif