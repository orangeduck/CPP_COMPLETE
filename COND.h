#ifndef COND_H
#define COND_H

#include "CORE.h"

/* Conditional Expression */

/*
 * !! Warning !!
 *
 *  Both sides of the conditional will
 *  be fully evaluated. The preprocessor
 *  will THEN pick which side to use.
 *
 *  It is important to take this into
 *  account because evaluating an errorous
 *  expression on the FALSE side will crash
 *  the preprocessor even if it is unused.
 *
 *  This also becomes an issue for recursion
 *  as the preprocessor will continue to
 *  evaluate the loop until it hits the
 *  recursion limit, even if because of
 *  a conditional it will never be used.
 *
 *  See RECR.h for what I have done to
 *  avoid this behaviour.
 *
 */

#define IF_ELSE(C, T, E) JOIN(IF_ELSE_, C)(T, E)
#define IF_ELSE_0(T, E) E
#define IF_ELSE_1(T, E) T

#define IF(C, T) IF_ELSE(C, T, )
  
#endif