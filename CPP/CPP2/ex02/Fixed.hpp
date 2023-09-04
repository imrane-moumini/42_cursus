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
    Fixed& min(Fixed& nbr1, Fixed& nbr2);
    Fixed& min(const Fixed& nbr1, const Fixed& nbr2);
    Fixed& max(Fixed& nbr1, Fixed& nbr2);
    Fixed& max(const Fixed& nbr1, const Fixed& nbr2);
    //overloading
    bool operator>(Fixed& obj);
    bool operator<(Fixed& obj);
    bool operator>=(Fixed& obj);
    bool operator<=(Fixed& obj);
    bool operator==(Fixed& obj);
    bool operator!=(Fixed& obj);
    int  operator+(Fixed& obj);
    int  operator-(Fixed& obj);
    int  operator*(Fixed& obj);
    int  operator/(Fixed& obj);
    Fixed&  operator++(int nbr);
    Fixed&  operator--(int nbr);
    

private:
    int StockEnt;
    static const int NbrBytesFr = 8;

};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);
#endif