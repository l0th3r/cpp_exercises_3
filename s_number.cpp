#include "s_number.h"


// TEMP

#include <iostream>

// TEMP


s_number operator+(const s_number& a, const s_number& b)
{
    s_number result;

    // store length of elements
    size_t aLen = a._value.length();
    size_t bLen = b._value.length();
    size_t maxLen = std::max(aLen, bLen);

    size_t i = 0;

    int ret = 0;
    while(i < maxLen)
    {
        int som = 0;
        int top = 0;
        int bot = 0;

        if(i < aLen)
            top = a._value[aLen - (i + 1)] - '0';

        if(i < bLen)
            bot = b._value[bLen - (i + 1)] - '0';

        som = top + bot + ret;
        ret = 0;

        if(som > 9)
        {
            std::string ssom = std::to_string(som);
        }

        std::cout << som << std::endl;

        i++;
    }

    return result;
}
