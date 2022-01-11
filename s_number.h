#ifndef S_NUMBER_H
#define S_NUMBER_H

#include <string>

struct s_number {std::string _value;};

s_number operator+(const s_number& a, const s_number& b);
s_number operator-(const s_number& a, const s_number& b);



#endif // S_NUMBER_H
