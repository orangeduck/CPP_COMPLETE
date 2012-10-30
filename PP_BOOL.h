#ifndef PP_BOOL_H
#define PP_BOOL_H

#define PP_NOT_0 1
#define PP_NOT_1 0

#define PP_AND_0_0 0
#define PP_AND_0_1 0
#define PP_AND_1_0 0
#define PP_AND_1_1 1

#define PP_OR_0_0 0
#define PP_OR_0_1 1
#define PP_OR_1_0 1
#define PP_OR_1_1 1

#define PP_XOR_0_0 0
#define PP_XOR_0_1 1
#define PP_XOR_1_0 1
#define PP_XOR_1_1 0

/* Truth Constants */
#define PP_TRUE 1
#define PP_FALSE 0

/* Boolean Operators */
#define PP_NOT(X) PP_JOIN(PP_NOT_, X)
#define PP_AND(X, Y) PP_JOIN2(PP_AND_, X, Y)
#define PP_OR(X, Y) PP_JOIN2(PP_OR_, X, Y)
#define PP_XOR(X, Y) PP_JOIN2(PP_XOR_, X, Y)

/* Cast to Bool */
#define PP_CHECK_N(X, N, ...) N
#define PP_CHECK(...) PP_CHECK_N(__VA_ARGS__, 0,)

#define PP_CHECK_ZERO(X) PP_CHECK(PP_JOIN(PP_CHECK_ZERO_, X))
#define PP_CHECK_ZERO_0 ~, 1,

#define PP_CHECK_EMPTY(X) PP_CHECK(PP_JOIN(PP_CHECK_EMPTY_, X))
#define PP_CHECK_EMPTY_ ~, 1,


#define PP_BOOL(X) PP_NOT(PP_CHECK_ZERO(X))

#endif