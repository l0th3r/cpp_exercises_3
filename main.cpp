#include <iostream>
#include "s_number.h"

int main()
{
    s_number sa = {"125"};
    s_number sb = {"455"};

    s_number sc = sa + sb;

    std::cout << sc._value << std::endl;

    return 0;
}
