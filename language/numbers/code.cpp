#include "main.h"

#include <iostream>

extern int a;

namespace named {

void aar()
{
    using namespace std;
    cout << "a was " << a << endl;
    ++a;
    cout << "a now is " << a << endl;
    ++e;
}

void bar()
{
    using namespace std;
    cout << "b was " << b << endl;
    ++b;
    cout << "b now is " << b << endl;
    ++e;
    cout << "e from code.cpp " << e << endl;
}

} // namespace named
