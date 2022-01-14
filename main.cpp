#include <iostream>
#include "s_number.h"

// msb 1011 lsb

int main()
{
    s_number sa = {"999"};
    s_number sb = {"32"};
    s_number sc = sa*sb;

    std::cout << sc._value << std::endl;

    return 0;
}
