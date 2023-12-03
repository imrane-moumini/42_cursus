#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
class Fixed{
public:
    Fixed();
    Fixed(const Fixed& rhs);
    Fixed& operator=(const Fixed& rhs);
    Fixed(const int  nbr);
    Fixed(const float nbr);
   
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt (void) const;
    float toFloat(void) const;
private:
    int StockEnt;
    static const int NbrBytesFr = 8;

};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);
#endif