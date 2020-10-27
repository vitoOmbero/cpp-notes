#include "main.h"

#include <ctime>
#include <iostream>

#include <cstdlib>

using namespace std;

int a{};

void foo()
{
    static int c{};
    cout << c << endl;
}

namespace named
{
int d{};
}

namespace
{
int        f{};
static int g{};
} // namespace

int    last_rnd = 0;
time_t timer    = time(NULL);

void srand()
{
    last_rnd = std::time(&timer);
}

int rand()
{
    last_rnd = (last_rnd * 13 + 113) % 43;
    return last_rnd;
}

void numbers()
{
    using namespace std;
    named::aar();
    cout << a << endl;
    named::bar();
    cout << b << endl;
    foo();
    cout << named::d << endl;
    cout << "e from main.cpp " << named::e << endl;

    cout << f << endl;
    cout << g << endl;
}

void clocks()
{
    cout << "clock" << endl;
    srand();
    for (; a < 10; ++a)
        cout << rand() << endl;
    cout << "clock end" << endl;
}

void c_alloc()
{
    int* ptr = static_cast<int*>(malloc(1000000 * sizeof(int)));

    // ... code w/o free(ptr);

    ptr = static_cast<int*>(malloc(4242 * sizeof(int)));

    if (ptr == NULL)
    {
        /* not enough memory C++03*/
    }
    if (ptr == nullptr)
    {
        /* not enough memory C++11*/
    }
    if (ptr == 0)
    {
        /* not enough memory C99*/
    }
    if (!ptr)
    {
        /* not enough memory C99*/
    }
    ptr[0]    = 1;
    ptr[4242] = 42;

    cout << ptr[4242] << endl;

    free(ptr);
}

int main()
{
    return 0;
}
