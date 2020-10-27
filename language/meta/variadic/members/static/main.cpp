#include <iostream>
#include <utility>

#include "main.h"

using namespace std;

void AtExit()
{
    StaticExecurter<void>::EnsureToBeExecuted();
};

int main()
{
    cout << StaticField<int, 6>::field << endl;
    cout << std::boolalpha
         << is_same<StaticField<int, 6>, StaticField<int, 7>>()
         << std::noboolalpha << endl;
    cout << endl;

    cout << "Defined Type and Value" << endl;

    cout << DefinedTypeValDerived::field << endl;
    cout << endl;

    cout << "Defined Type only (set 777)" << endl;
    DefinedTypeDerived::Init(777);
    cout << DefinedTypeDerived::field << endl;
    cout << endl;

    cout << "User type (set 42.42)" << endl;
    Derived<float>::Init(42.42);

    cout << Derived<float>::field << endl;

    cout << "Derived object (float) and (set 43.1)" << endl;
    Derived<int> d2;
    d2.Init(43.);

    cout << Derived<float>::field << endl;
    cout << d2.field << endl;

    cout << "Derived object (double) (was satically executed at compile time) "
            "(set 99.99)"
         << endl;
    cout << Derived<double>::field << endl;
    return 0;
}
