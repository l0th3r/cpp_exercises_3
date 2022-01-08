#include "s_number.h"


// TEMP

#include <iostream>
int ctoi(const char);

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
            top = ctoi(a._value[aLen - (i + 1)]);

        if(i < bLen)
            bot = ctoi(b._value[bLen - (i + 1)]);

        som = top + bot + ret;
        ret = 0;

        if(som > 9)
        {
            std::string ssom = std::to_string(som);
            som = ctoi(ssom[ssom.length() - 1]);
            ssom.erase(ssom.length() - 1, 1);
            ret = std::stoi(ssom);
        }

        result._value.insert(0, std::to_string(som));
        i++;
    }

    return result;
}

s_number operator-(const s_number& a, const s_number& b)
{
    s_number result;




    return result;
}

int ctoi(const char c)
{
    return c - '0';
}
