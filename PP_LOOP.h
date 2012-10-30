#ifndef PP_LOOP_H
#define PP_LOOP_H

#include "PP_COND.h"

#define PP_FOR(C, M, U, E, X)  PP_IF_ELSE( C(X), M(X) PP_FOR9(C, M, U, E, U(X)), E(X) ) 

#define PP_FOR9(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR8(C, M, U, E, U(X)), E(X) )
#define PP_FOR8(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR7(C, M, U, E, U(X)), E(X) )  
#define PP_FOR7(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR6(C, M, U, E, U(X)), E(X) )  
#define PP_FOR6(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR5(C, M, U, E, U(X)), E(X) ) 
#define PP_FOR5(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR4(C, M, U, E, U(X)), E(X) ) 
#define PP_FOR4(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR3(C, M, U, E, U(X)), E(X) ) 
#define PP_FOR3(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR2(C, M, U, E, U(X)), E(X) ) 
#define PP_FOR2(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR1(C, M, U, E, U(X)), E(X) ) 
#define PP_FOR1(C, M, U, E, X) PP_IF_ELSE( C(X), M(X) PP_FOR0(C, M, U, E, U(X)), E(X) ) 
#define PP_FOR0(C, M, U, E, X) PP_STACK_OVERFLOW

#endif