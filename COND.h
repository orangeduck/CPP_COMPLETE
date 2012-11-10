#ifndef COND_H
#define COND_H

#include "CORE.h"

#define IF_ELSE(C, T, E) JOIN(IF_ELSE_, C)(T, E)
#define IF_ELSE_0(T, E) E
#define IF_ELSE_1(T, E) T

#define IF(C, T) IF_ELSE(C, T, )
  
#endif