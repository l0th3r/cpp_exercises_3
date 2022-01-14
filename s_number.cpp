#include "s_number.h"

#include <iostream> // temp

int ctoi(const char);
void clean_snumber(s_number& snb);

s_number add(const s_number& a, const s_number& b);
s_number sub(const s_number& a, const s_number& b);
s_number mul(const s_number& a, const s_number& b);
s_number div(const s_number& a, const s_number& b);
s_number mod(const s_number& a, const s_number& b);

// tools
int ctoi(const char c)
{
    return c - '0';
}

void clean_snumber(s_number& snb)
{
    int start = 0;

    if(snb._value[0] == '-')
        start = 1;

    while(snb._value[start] == '0')
    {
        std::cout << snb._value << std::endl;
        snb._value.erase(start, 1);
    }

    if(snb._value.length() == 0)
        snb._value = "0";
}

// operators
s_number operator+(const s_number& a, const s_number& b)
{
    return add(a, b);
}

s_number operator-(const s_number& a, const s_number& b)
{
    return sub(a, b);
}

s_number operator+(const s_number& a)
{
    return a;
}

s_number operator-(const s_number& a)
{
    s_number res = a;

    if(a._value[0] != '-')
        res._value.insert(0, "-");
    else
        res._value.erase(0, 1);

    return res;
}

s_number operator*(const s_number& a, const s_number& b)
{
    return mul(a, b);
}


// algorithms
s_number mul(const s_number& a, const s_number& b)
{
    s_number result;

    s_number top_res;
    s_number bot_res = {"0"};

    // store length of elements
    size_t aLen = a._value.length();
    size_t bLen = b._value.length();

    int ret = 0;

    size_t i = 0;
    size_t j = 0;
    while(i < bLen)
    {
        int bot = ctoi(b._value[bLen - (i + 1)]);

        j = 0;
        ret = 0;
        while(j < aLen)
        {
            int top = ctoi(a._value[aLen - (j + 1)]);
            int mul_res = (bot * top) + ret;
            ret = 0;

            if(mul_res > 9)
            {
                // convert result to string then chop string and place ret and result
                std::string smul_res = std::to_string(mul_res);
                mul_res = ctoi(smul_res[smul_res.length() - 1]);
                smul_res.erase(smul_res.length() - 1, 1);
                ret = std::stoi(smul_res);
            }

            if(i == 0)
                top_res._value.insert(0, std::to_string(mul_res));
            else
                bot_res._value.insert(0, std::to_string(mul_res));

            j++;
        }

        if(ret > 0 && i == 0)
            top_res._value.insert(0, std::to_string(ret));
        else if(ret > 0)
            bot_res._value.insert(0, std::to_string(ret));

        i++;
    }

    clean_snumber(top_res);
    clean_snumber(bot_res);
    result = top_res + bot_res;

    return result;
}

s_number sub(const s_number& first, const s_number& second)
{
    s_number result;

    // copy value to be able to modify it
    s_number a = first;
    s_number b = second;

    // store length of elements
    size_t aLen = a._value.length();
    size_t bLen = b._value.length();
    size_t maxLen = std::max(aLen, bLen);

    size_t i = 0;
    while(i < maxLen)
    {
        int sub = 0;    // result of substraction
        int top = 0;    // top element
        int bot = 0;    // bottom element

        // parse character to value if exist
        if(i < aLen)
            top = ctoi(a._value[aLen - (i + 1)]);

        if(i < bLen)
            bot = ctoi(b._value[bLen - (i + 1)]);

        // if top is less than bot, use the anglo-saxon method
        // add 10 to top and do -1 to top's left element
        if(top < bot)
        {
            top += 10;
            a._value[aLen - (i + 2)] = (ctoi(a._value[aLen - (i + 2)]) - 1) + '0';
        }

        sub = top - bot;
        result._value.insert(0, std::to_string(sub));

        i++;
    }

    clean_snumber(result);
    return result;
}

s_number add(const s_number& a, const s_number& b)
{
    s_number result;

    // store length of elements
    size_t aLen = a._value.length();
    size_t bLen = b._value.length();
    size_t maxLen = std::max(aLen, bLen);

    int ret = 0;

    size_t i = 0;
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
            // convert som to string then chop string and place ret and result
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

