#ifndef PP_LIST_H
#define PP_LIST_H

#include "PP_CORE.h"
#include "PP_BOOL.h"
#include "PP_RECR.h"

#define PP_LIST(...) (__VA_ARGS__)
#define PP_UNCURRY(M, ...) M(__VA_ARGS__)
#define PP_CURRY(M, L) PP_EVAL(M L)

#define PP_HEAD(L) PP_CURRY(PP_LIST_HEAD, L)
#define PP_TAIL(L) PP_CURRY(PP_LIST_TAIL, L)
#define PP_FST(L) PP_HEAD(L)
#define PP_SND(L) PP_HEAD(PP_TAIL(L))
#define PP_TRD(L) PP_HEAD(PP_TAIL(PP_TAIL(L)))
#define PP_FTH(L) PP_HEAD(PP_TAIL(PP_TAIL(PP_TAIL(L))))
#define PP_ISEMPTY(L) PP_CHECK_EMPTY(PP_HEAD(L))
#define PP_CONS(X, L) PP_IF_ELSE(PP_ISEMPTY(L), (X), (X, PP_CURRY(PP_EVAL, L)))
#define PP_CONCAT(L, G) PP_IF_ELSE( PP_ISEMPTY(L), G, PP_IF_ELSE(PP_ISEMPTY(G), L, (PP_CURRY(PP_EVAL, L), PP_CURRY(PP_EVAL, G)) ))

#define PP_LEN_C($, X) PP_NOT(PP_ISEMPTY(PP_FST(X)))
#define PP_LEN_M($, X)
#define PP_LEN_U($, X) (PP_TAIL(PP_FST(X)), PP_INC(PP_SND(X)))
#define PP_LEN_E($, X) PP_SND(X)
#define PP_LEN($, L) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_LEN_C, PP_LEN_M, PP_LEN_U, PP_LEN_E, (L, 0))

#define PP_NTH_C($, X) PP_BOOL(PP_SND(X))
#define PP_NTH_M($, X)
#define PP_NTH_U($, X) ( PP_TAIL(PP_FST(X)), PP_DEC(PP_SND(X)) )
#define PP_NTH_E($, X) PP_HEAD(PP_FST(X))
#define PP_NTH($, L, N) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_NTH_C, PP_NTH_M, PP_NTH_U, PP_NTH_E, (L, N))

#define PP_TAKE_C($, X) PP_BOOL(PP_SND(X))
#define PP_TAKE_M($, X) 
#define PP_TAKE_U($, X) (PP_FST(X), PP_DEC(PP_SND(X)), PP_CONS(PP_HEAD(PP_FST(X)), PP_TRD(X)))
#define PP_TAKE_E($, X) PP_TRD(X)
#define PP_TAKE($, L, N) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_TAKE_C, PP_TAKE_M, PP_TAKE_U, PP_TAKE_E, (L, N, ()))

#define PP_DROP_C($, X) PP_BOOL(PP_SND(X))
#define PP_DROP_M($, X) 
#define PP_DROP_U($, X) (PP_TAIL(PP_FST(X)), PP_DEC(PP_SND(X)))
#define PP_DROP_E($, X) PP_FST(X)
#define PP_DROP($, L, N) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_DROP_C, PP_DROP_M, PP_DROP_U, PP_DROP_E, (L, N))

#define PP_LIST_HEAD(X, ...) X
#define PP_LIST_TAIL(X, ...) (__VA_ARGS__)



#endif