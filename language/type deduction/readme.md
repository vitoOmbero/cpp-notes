## links

- https://en.cppreference.com/w/cpp/language/typeid
- https://docs.microsoft.com/en-us/cpp/cpp/auto-cpp?view=vs-2017
- https://www.oreilly.com/library/view/effective-modern-c/9781491908419/ch01.html
 - https://github.com/CppCon/CppCon2014/blob/master/Presentations/Type%20Deduction%20and%20Why%20You%20Care/%2B%2B%20Type%20Deduction%20and%20Why%20You%20Care%20-%20Scott%20Meyers%20-%20CppCon%202014%20-%20CppCon%202014.pdf
- https://en.cppreference.com/w/cpp/language/decltype
- https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers

## Q?

* auto type deduction and template type deduction?
* Univerasal reference?
* decltype: purpose, using?
* C-array size with help of referene at compile time?
* When auto should be used?
* std::initializer_list in С++11, С++14, С++17


### Type inference or type deduction

```c++
int a = 5;
double b = 4.5;
auto c = a; // int
auto d = 5ul; // unsigned long
```

```c++
template<typename Т>
void f ( Targ param ) ; // Targ is T& either T* in this case
```

*Targ*: **ptr** or **ref** are ignored for *T*

```c++
int х= 27;
const int сх = х; 
const int& rx = х; 

f(х); //Т - int, Targ - int&
f(cx); // Т - const int, Targ - const int&
f (rx) ; // Т - const int, Targ - const int&
```

```c++
template<typename Т>
void f ( T&& param ) ; // Targ – T&&
```

Universal ref:
• if *expression* is *lvalue*, then *Т* and *ParamType* are deducted as lvaluе refs.
• case of *rvalue* – simply and similar

```c++
int х= 27; 
const int сх = х; 
const int& rx = х;

f(х); // x – lvalue => Т == Targ - int&
f(cx); // cx – lvalue => Т == Targ – const int&
f(rx) ; // rx – lvalue => Т == Targ – const int&
f(27); // 27 – rvalue => T – int, Targ – int&&
```

```c++
template<typename Т>
void f ( T param ) ; // by value
```

Targ: nor *ptr*, neihther *ref*
• cv and ref are dropped – new C++-object is created


## C-array ref

```c++
template<typeпame Т, std::size_t N>
constexpr std::size_t arraySize (T (&) [N] ) nоехсерt
{ return N; }
```

##Automatically (auto)

No difference.

Exception for std::initializer_list:

```c++
auto xl = 27; // int, val = 27
auto х2(27); // int, val = 27

auto хЗ = { 27 } ; // std::initializer_list<int>, val{27}
auto х4{ 27 }; // std::initializer_list<int>, val{27}
```

Universal reference:

```c++
auto&& uref1 = x; //х - int and lvalue, => uref1 - int& сх;
auto&& uref2 = cx; // сх - const int and lvalue, => uref2 - const int&
auto&& uref3 = 27; // 27 - int and rvalue, => uref3 - int&&
```

##decltype, decltype(auto)

Declared type is used with decltуре (С++11) in function template declaration where return type depends on function arguments' types.

decltype(auto) - type will be deducted
decltype - there are decltype rules applied in deduction process.

```c++
int x;
```
х (as symbolic name) is *lvalue*, so does an expression (х),
=> 
decltype ( (х) ) is *int&*.

*Brackets change the result type*.
