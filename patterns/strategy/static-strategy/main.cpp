#include <iostream>

// #include "printer_policy.h"
#include "printer_combine_policy.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    using PlusPrinter =
        lib::Printer<lib::PlusPrintPolicy, lib::LineSeparationPolicy>;

    PlusPrinter plus_pr;

    lib::MyClass o1{ 42 };

    plus_pr.PrintToOut(o1);

    using LatticePrinter = lib::Printer<lib::LatticePrintPolicy>;

    LatticePrinter lat_pr;

    lat_pr.PrintToOut(o1);

#ifdef COMBINE

#endif

    return 0;
}
