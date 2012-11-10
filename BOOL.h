#ifndef BOOL_H
#define BOOL_H

#define NOT_0 1
#define NOT_1 0

#define AND_0_0 0
#define AND_0_1 0
#define AND_1_0 0
#define AND_1_1 1

#define OR_0_0 0
#define OR_0_1 1
#define OR_1_0 1
#define OR_1_1 1

#define XOR_0_0 0
#define XOR_0_1 1
#define XOR_1_0 1
#define XOR_1_1 0

/* Truth Constants */
#define TRUE 1
#define FALSE 0

/* Boolean Operators */
#define NOT(X) JOIN(NOT_, X)
#define AND(X, Y) JOIN2(AND_, X, Y)
#define OR(X, Y) JOIN2(OR_, X, Y)
#define XOR(X, Y) JOIN2(XOR_, X, Y)

/* Cast to Bool */
#define CHECK_N(X, N, ...) N
#define CHECK(...) CHECK_N(__VA_ARGS__, 0,)

#define CHECK_ZERO(X) CHECK(JOIN(CHECK_ZERO_, X))
#define CHECK_ZERO_0 ~, 1,

#define CHECK_EMPTY(X) CHECK(JOIN(CHECK_EMPTY_, X))
#define CHECK_EMPTY_ ~, 1,


#define BOOL(X) NOT(CHECK_ZERO(X))

#endif