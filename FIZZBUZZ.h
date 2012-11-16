#include "COMPLETE.h"

/*! Thought it was time to hop on this band wagon */

#define FIZZBUZZ_C($, X) LT($, X, 101)
#define FIZZBUZZ_M($, X) IF_ELSE( NOT(BOOL(MOD($, X, 15))) , FizzBuzz \
  , IF_ELSE( NOT(BOOL(MOD($, X, 3))) , Fizz \
  , IF_ELSE( NOT(BOOL(MOD($, X, 5))) , Buzz \
  , X \
  )))
#define FIZZBUZZ_U($, X) INC(X)
#define FIZZBUZZ_E($, X)
#define FIZZBUZZ() JOIN(RECR_D, 0)(1, FIZZBUZZ_C, FIZZBUZZ_M, FIZZBUZZ_U, FIZZBUZZ_E, 1)