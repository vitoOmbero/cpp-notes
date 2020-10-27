#include <iostream>

using namespace std;

int zero; // integral type, Zero Initialization

static int zero_too;

enum c_style_enumeration {
    the_first,
    the_second

};

enum class cpp_style_enum { first, second };

void foo()
{
    int second; // garbage
    cout << "second: " << second << endl;
}

void bar()
{
    int zero_too = 0;
    ::zero_too = 1;
    if (zero_too != ::zero_too)
        cout << "bar(): zero_too: " << zero_too << endl;
}

template<typename T>
T zoo(const T &in)
{
    return in;
}

int main()
{
    int first; // garbage by standart

    cout << "zero: " << zero << endl;
    bar();
    cout << "zero_too: " << zero_too << endl;
    cout << "first: " << first << endl; // warning here
    foo();

    // int first = 1; // compile error: redifinition;

    if (true) {
        int three = zoo(three);
        cout << "three: " << three << endl; // no warning here - legal garbage!
    }

    the_first; // warning: unused expression

    c_style_enumeration cenum; // garbage

    // c_ctyle_enum implicitly casts to int

    switch (cenum) {    // warning here (uninitialized value)
    case (the_first): { // c_style_enum name is visible
        cout << "cenum: c_style_enumeration::the_first : " << cenum << endl;
        break;
    }
    case (the_second): {
        cout << "cenum: c_style_enumeration::the_second : " << cenum << endl;
        break;
    } // there is no need in block scope for case really
    default:
        cout << "cenum: unvalid c_style_enumeration : " << cenum << endl;
        break;
    }

    cpp_style_enum cppenum = static_cast<cpp_style_enum>(2);
    cout << "cppenum, int cast: " << static_cast<int>(cppenum) << endl; // no warning here
    cout << "cppenum: " << static_cast<int>(cppenum) << endl;           // legal garbage

    cpp_style_enum enumval = cpp_style_enum::second;

    switch (enumval) {
    case (cpp_style_enum::first): {
        cout << "enumval: cpp_style_enum::first : " << static_cast<int>(enumval) << endl;
        break;
    }
    case (cpp_style_enum::second): {
        cout << "enumval: cpp_style_enum::second : " << static_cast<int>(enumval) << endl;
        break;
    }
    default:
        cout << "enumval: unsupported value : " << static_cast<int>(enumval) << endl;
        break;
    }

    /*
    cout << "Exit? (y)" << endl;
    char c;
    cin >> c;
    */

    return 0;
}
