#include <iostream>
#include "s_number.h"

// msb 1011 lsb

int main()
{
    s_number sa = {"92"};
    s_number sb = {"92"};
    s_number sc = sa / sb;

    std::cout << (sa <= sb) << std::endl;

    return 0;
}
