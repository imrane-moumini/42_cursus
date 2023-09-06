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
    static Fixed& min(Fixed& nbr1, Fixed& nbr2);
    static const Fixed& min(const Fixed&  nbr1,  const Fixed&  nbr2);
    static Fixed& max(Fixed& nbr1, Fixed& nbr2);
    static const Fixed& max( const Fixed&  nbr1,  const Fixed&  nbr2);
    //overloading
    bool operator>(const Fixed&  obj)  const ;
    bool operator<(const Fixed&  obj)  const ;
    bool operator>=(const Fixed&  obj)  const ;
    bool operator<=(const Fixed&  obj)  const ;
    bool operator==(const Fixed&  obj)  const ;
    bool operator!=(const Fixed&  obj)  const ;
    Fixed  operator+(const Fixed&  obj)  const ;
    Fixed  operator-(const Fixed&  obj)  const ;
    Fixed  operator*(const Fixed&  obj)  const ;
    Fixed  operator/(const Fixed&  obj)  const ;
    Fixed&  operator++();
    Fixed&  operator--();
    Fixed   operator++(int);
    Fixed   operator--(int);
    

private:
    int StockEnt;
    static const int NbrBytesFr = 8;

};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);
#endif