#ifndef PP_CORE_H
#define PP_CORE_H

#define PP_EMPTY() 
#define PP_DEFER(M) M PP_EMPTY()
#define PP_OBSTRUCT(M) M PP_DEFER(PP_EMPTY)()

#define PP_APPLY(M, ...) M(__VA_ARGS__)

#define PP_JOIN(X, Y) X##Y
#define PP_JOIN2(X, Y, Z) X##Y##_##Z

#define PP_EVAL(...) __VA_ARGS__
#define PP_EAT(...) 

#endif