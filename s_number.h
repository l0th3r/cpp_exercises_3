#ifndef S_NUMBER_H
#define S_NUMBER_H

#include <ostream>
#include <string>

struct s_number {std::string _value;};

s_number operator+(const s_number& a, const int& b);
s_number operator+(const s_number& a, const s_number& b);
s_number operator+(const s_number& a);
s_number operator-(const s_number& a, const s_number& b);
s_number operator-(const s_number& a);
s_number operator*(const s_number& a, const s_number& b);
s_number operator/(const s_number& a, const s_number& b);
s_number operator%(const s_number& a, const s_number& b);

std::ostream& operator<<(std::ostream& s, const s_number& a);
std::istream& operator>>(std::istream& s, s_number& a);

bool operator==(const s_number& a, const s_number& b);
bool operator!=(const s_number& a, const s_number& b);
bool operator>(const s_number& a, const s_number& b);
bool operator>=(const s_number& a, const s_number& b);
bool operator<(const s_number& a, const s_number& b);
bool operator<=(const s_number& a, const s_number& b);


#endif // S_NUMBER_H
