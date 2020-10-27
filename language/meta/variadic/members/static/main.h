#ifndef MAIN_H
#define MAIN_H

#include <utility>

template <class T, T val>
struct StaticField
{
    // inline - to supress out of line initialization
    inline static T field{ val }; // (c++17)
};

/// -----

template <class T>
struct DefinedTypeValBase
{
    inline static int field = T::Init();
};

struct DefinedTypeValDerived : DefinedTypeValBase<DefinedTypeValDerived>
{
    constexpr static int Init() { return 11; };
};

/// -----

template <class T>
struct DefinedTypeBase
{
    inline static int     field;
    constexpr static void Init(int val) { field = val; };
};

struct DefinedTypeDerived : DefinedTypeBase<DefinedTypeDerived>
{
};

/// -----

template <class T, typename U>
struct Base
{
    typedef U             field_type;
    inline static U       field;
    constexpr static void Init(U val) { field = val; };
};

template <typename U>
struct Derived : Base<Derived<U>, U>
{
};

// static init code
template <class DoesntReallyMatter>
class StaticExecurter // can't be namespace as constexpr DoAll can't modify
                      // something declared outside
{
private:
    constexpr static int DoAll()
    {
        Derived<double>::Init(99.99);
        return std::is_same<StaticExecurter, DoesntReallyMatter>();
    }
    inline static int executed_at_compiletime = DoAll();

public:
    inline static int EnsureToBeExecuted() { return executed_at_compiletime; };
};

#endif // MAIN_H
