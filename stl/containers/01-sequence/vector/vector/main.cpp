#include <iostream>
#include <vector>

using namespace std;

enum Case
{
    k1,
    k2,
    k3,
    k4
};

void* operator new(std::size_t n)
{
    std::cout << "[allocating " << n << " bytes]\n";
    return malloc(n);
}

int n = 10;
int N = 10;

void set_case(Case c)
{

    switch (c)
    {
        case k1:
        {
            n = 1;
            N = 1;
            return;
        }
        case k2:
        {
            n = 1;
            N = 10;
            return;
        }
        case k3:
        {
            n = 10;
            N = 10;
            return;
        }
        case k4:
        {
            n = 11;
            N = 10;
            return;
        }
    }
}

int main()
{

    set_case(k4);

    vector<int> v(n);

    cout << "size: " << v.size() << endl;
    cout << "cap: " << v.capacity() << endl;

    for (int i = 0; i < N; ++i)
    {
        v[i] = i;
    }

    cout << "=> Loop end" << endl;

    v.shrink_to_fit();

    cout << "size: " << v.size() << endl;
    cout << "cap: " << v.capacity() << endl;

    v.push_back(9000);

    cout << "=> Add one more " << endl;

    cout << "size: " << v.size() << endl;
    cout << "cap: " << v.capacity() << endl;

    return 0;
}
