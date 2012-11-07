#ifndef PP_COND_H
#define PP_COND_H

#include "PP_CORE.h"

#define PP_IF_ELSE(C, T, E) PP_JOIN(PP_IF_ELSE_, C)(T, E)
#define PP_IF_ELSE_0(T, E) E
#define PP_IF_ELSE_1(T, E) T

#define PP_IF(C, T) PP_IF_ELSE(C, T, )
  
#endif