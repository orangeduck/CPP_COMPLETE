#ifndef LIST_H
#define LIST_H

#include "CORE.h"
#include "BOOL.h"
#include "RECR.h"

/* Primative list data structure */

#define LIST(...) (__VA_ARGS__)
#define UNCURRY(M, ...) M(__VA_ARGS__)
#define CURRY(M, L) EVAL(M L)

#define HEAD(L) CURRY(LIST_HEAD, L)
#define TAIL(L) CURRY(LIST_TAIL, L)
#define FST(L) HEAD(L)
#define SND(L) HEAD(TAIL(L))
#define TRD(L) HEAD(TAIL(TAIL(L)))
#define FTH(L) HEAD(TAIL(TAIL(TAIL(L))))
#define ISEMPTY(L) CHECK_EMPTY(HEAD(L))
#define CONS(X, L) IF_ELSE(ISEMPTY(L), (X), (X, CURRY(EVAL, L)))
#define CONCAT(L, G) IF_ELSE( ISEMPTY(L), G, IF_ELSE(ISEMPTY(G), L, (CURRY(EVAL, L), CURRY(EVAL, G)) ))

#define LEN_C($, X) NOT(ISEMPTY(FST(X)))
#define LEN_M($, X)
#define LEN_U($, X) (TAIL(FST(X)), INC(SND(X)))
#define LEN_E($, X) SND(X)
#define LEN($, L) JOIN(RECR_D, $)(INC($), LEN_C, LEN_M, LEN_U, LEN_E, (L, 0))

#define NTH_C($, X) BOOL(SND(X))
#define NTH_M($, X)
#define NTH_U($, X) ( TAIL(FST(X)), DEC(SND(X)) )
#define NTH_E($, X) HEAD(FST(X))
#define NTH($, L, N) JOIN(RECR_D, $)(INC($), NTH_C, NTH_M, NTH_U, NTH_E, (L, N))

#define TAKE_C($, X) BOOL(SND(X))
#define TAKE_M($, X) 
#define TAKE_U($, X) (TAIL(FST(X)), DEC(SND(X)), CONCAT(TRD(X), (HEAD(FST(X)))))
#define TAKE_E($, X) TRD(X)
#define TAKE($, L, N) JOIN(RECR_D, $)(INC($), TAKE_C, TAKE_M, TAKE_U, TAKE_E, (L, N, ()))

#define DROP_C($, X) BOOL(SND(X))
#define DROP_M($, X) 
#define DROP_U($, X) (TAIL(FST(X)), DEC(SND(X)))
#define DROP_E($, X) FST(X)
#define DROP($, L, N) JOIN(RECR_D, $)(INC($), DROP_C, DROP_M, DROP_U, DROP_E, (L, N))

#define LIST_HEAD(X, ...) X
#define LIST_TAIL(X, ...) (__VA_ARGS__)



#endif