#ifndef CORE_H
#define CORE_H

#define EMPTY() 
#define DEFER(M) M EMPTY()
#define OBSTRUCT(M) M DEFER(EMPTY)()

#define APPLY(M, ...) M(__VA_ARGS__)

#define JOIN(X, Y) X##Y
#define JOIN2(X, Y, Z) X##Y##_##Z

#define EVAL(...) __VA_ARGS__
#define EAT(...)

#define ERROR() (ERROR)##(ERROR)

#endif