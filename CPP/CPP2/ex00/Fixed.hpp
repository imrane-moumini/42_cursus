#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cstring>
#include <string>

class Fixed{
public:
    Fixed();
    ~Fixed();
    Fixed(Fixed& rhs);
    Fixed& operator=(Fixed& rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);
private:
    int StockEnt;
    static const int NbrBytesFr = 8;

};
#endif