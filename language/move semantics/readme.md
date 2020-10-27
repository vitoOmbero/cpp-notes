todo

## Q?

- rvalue reference from universal (forwarding) reference difference?
- std::forward?
- std::move?
- When RVO & std::move is good?
- Connection noexcept & std::move?

# notes

```txt
                    lvalue
            glvalue
expression          xvalue
            rvalue
                    prvalue
```

gl-value for C++-object (or bit-field) identity
pr-value for unnamed result of operators operand or initialization value
x-value  for gl-value, which owned resourses may be reused
l-value  for gl-value which is not x-value (owned resourses may not be reused, historically)
r-value  for x-value or pr-value (historically)

lvalue has adress.
rvalue has no adress.

Universal reference (forwarding reference) - T&&, auto&& - in scope of template or auto
rvalue reference - Class&&
lvalue reference - Class&

This value categories are used in scope of expressions in C++ language.
rvalue reference as unit of expression can be named and may have value category of *lvalue*.

reference collapsing:
T&& T&& -> T&&
T&& T& -> T&
T& T&& -> T&
T& T& -> T&

Temporary C++-objects may not have a name.

std::move() – static_cast to Rvalue reference.
std::forward() – the same for templates.
std::remove_reference – for templates.
std::decay – std::remove_reference + omit cv-qualification.

Autogenration (move) for class with no copy (=,ctor), move (=,ctor), destructor declarations.

Template strict value:

```c++
template <typename T1, typename T2> void outer(T1&& t1, T2&& t2)
{
    inner(std::forward<T1>(t1), std::forward<T2>(t2));
}
```

## links

https://ru.cppreference.com/w/cpp/language/value_category
http://thbecker.net/articles/rvalue_references/section_01.html
https://www.ibm.com/support/knowledgecenter/en/SSGH3R_16.1.0/com.ibm.xlcpp161.aix.doc/langua
ge_ref/lvalue.html
https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-
cpp?view=vs-2017