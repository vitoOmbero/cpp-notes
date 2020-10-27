## what

Object oriented view of procedural subprogram with state, which persistance is limited by subprogram flow lifetime.

## Q?

- Pointer to function? C-style, C++-style.
- Functor? When are used f-ptrs and functors?
- std::function?
- lambda-expressions?
- std::bind - how to use, which C++ standarts?

## notes

* class Functor – C++ class with overloaded operator(), (no refs to functions, but functors)

```c++
class Functor
{
public:
void operator() ()
{
//some operation;
}
};
```

* []{} – minimal lambda expression,

```c++
[=] () mutable throw() -> int
{
    // algo
    return result;
}
```

* std::function – polymorphic wrapper for uniform function (function, lambda, bind).
* Init capture – С++14 capture list for labda-expressions.
* Std::bind – function call redirection with (optional) named, precalculated, reordered arguments,
* f_ptr – ponter to functon with its signature. Name for C++-object with function.

```c++
void (*func)(int a, int b);

int (Class::*member)(float, char, char);

char * ( *func (int, int) )( int, double );

typedef char* (*SomeFunction)(int, double);
SomeFunction func(int, int);
```
  