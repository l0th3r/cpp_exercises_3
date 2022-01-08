#include <iostream>
#include "s_number.h"

int main()
{
    s_number sa = {"176"};
    s_number sb = {"453"};

    s_number sc = sa + sb;

    std::cout << sc._value << std::endl;

    return 0;
}
