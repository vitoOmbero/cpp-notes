#ifndef PRINTER_STRATEGIES_H
#define PRINTER_STRATEGIES_H

#include <iostream>
#include <string>

namespace lib
{

template <class T>
struct IsPrintable
{
    static const bool value{ false };
};

struct MyClass
{
    int                  id;
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);
};

std::ostream& operator<<(std::ostream& os, const MyClass& obj)
{
    os << obj.id;
    return os;
}

template <>
struct IsPrintable<MyClass>
{
    static const bool value{ true };
};

struct Gnome
{
    int                  id;
    friend std::ostream& operator<<(std::ostream& os, const Gnome& obj);
};

std::ostream& operator<<(std::ostream& os, const Gnome& obj)
{
    os << obj.id << R"ASCII(
           ,-.
            ) \
        .--'   |
       /       /
       |_______|
      (  O   O  )
       {'-(_)-'}
     .-{   ^   }-.
    /   '.___.'   \
   /  |    o    |  \
   |__|    o    |__|
   (((\_________/)))
       \___|___/
     .--' | | '--.
     \__._| |_.__/
)ASCII";
    return os;
}

// policies

template <class T>
struct LatticePrintPolicy
{
    static void Print(T& obj)
    {
        std::cout << "#######";
        std::cout << obj;
        std::cout << "#######";
    }
};

template <class T>
struct PlusPrintPolicy
{
    static void Print(T& obj)
    {
        std::cout << "+++++++";
        std::cout << obj;
        std::cout << "+++++++";
    }
};

namespace
{
static const char* kNewLineSeparator = "/n";
}

template <template <class> class PrintPolicy>
class Printer
{
public:
    void PrintToOut(MyClass& obj) { print_p_.Print(obj); };

private:
    PrintPolicy<MyClass> print_p_;
};

} // namespace lib
#endif // PRINTER_STRATEGIES_H
