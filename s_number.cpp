#include "s_number.h"

#include <iostream> // temp

int ctoi(const char);
void clean_snumber(s_number& snb);
void equilibrate_length(s_number& sa, s_number& sb);

s_number add(const s_number& a, const s_number& b);
s_number sub(const s_number& a, const s_number& b);
s_number mul(const s_number& a, const s_number& b);
void div(const s_number& a, const s_number& b, s_number& result, s_number& rest);

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
        snb._value.erase(start, 1);
    }

    if(snb._value.length() == 0)
        snb._value = "0";
}

void equilibrate_length(s_number& sa, s_number& sb)
{
    if(sa._value.length() > sb._value.length())
    {
        while(sa._value.length() != sb._value.length())
        {
            sb._value.insert(0, "0");
        }
    }
    else if(sb._value.length() > sa._value.length())
    {
        while(sb._value.length() != sa._value.length())
        {
            sa._value.insert(0, "0");
        }
    }
}
//tools



// conditional operators

bool operator==(const s_number& a, const s_number& b)
{
    return (a._value == b._value);
}

bool operator!=(const s_number& a, const s_number& b)
{
    return !(a == b);
}

bool operator>(const s_number& a, const s_number& b)
{
    bool res = false;
    s_number sa = a;
    s_number sb = b;

    clean_snumber(sa);
    clean_snumber(sb);
    equilibrate_length(sa, sb);

    int i = 0;
    int ia = 0;
    int ib = 0;

    while(ia == ib && i < (int)sa._value.length())
    {
        ia = ctoi(sa._value[i]);
        ib = ctoi(sb._value[i]);

        if(ia > ib)
            res = true;

        i++;
    }

    return res;
}

bool operator>=(const s_number& a, const s_number& b)
{
    bool res = (a > b);

    if(!res)
    {
        res = (a == b);
    }

    return res;
}

bool operator<(const s_number& a, const s_number& b)
{
    if(a == b)
        return false;
    else
        return (b > a);
}

bool operator<=(const s_number& a, const s_number& b)
{
    if(a == b)
        return true;
    else
        return (b > a);
}

// conditional operators


// operators

// +
s_number operator+(const s_number& a, const s_number& b)
{
    // handle negative numbers
    return add(a, b);
}

s_number operator+(const s_number& a, const int& b)
{
    s_number sb = {std::to_string(b)};
    return add(a, sb);
}

s_number operator+(const s_number& a)
{
    return a;
}

// -
s_number operator-(const s_number& a, const s_number& b)
{
    // handle negative numbers
    return sub(a, b);
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

// *
s_number operator*(const s_number& a, const s_number& b)
{
    // handle negative numbers
    return mul(a, b);
}

// /
s_number operator/(const s_number& a, const s_number& b)
{
    s_number result;
    s_number rest;

    // handle negative numbers
    div(a, b, result, rest);

    return result;
}

s_number operator%(const s_number& a, const s_number& b)
{
    s_number result;
    s_number rest;

    // handle negative numbers
    div(a, b, result, rest);

    return rest;
}
// operators


// algorithms
void div(const s_number& a, const s_number& b, s_number& result, s_number& rest)
{
    result = {"0"};
    rest = a;

    while(rest >= b)
    {
        rest = rest - b;
        result = result + 1;
    }
}

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

    if(ret > 0)
        result._value.insert(0, std::to_string(ret));

    return result;
}

// stream
std::ostream& operator<<(std::ostream& s, const s_number& a)
{
    s << a._value;
    return s;
}

std::istream& operator>>(std::istream& s, s_number& a)
{
    s >> a._value;
    return s;
}
