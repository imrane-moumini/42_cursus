#include "Fixed.hpp"

Fixed::Fixed(){
    StockEnt = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &rhs){
    std::cout << "Copy constructor called" << std::endl;
    StockEnt = rhs.getRawBits();
}

Fixed& Fixed::operator=(Fixed &rhs){
    std::cout << "Copy assignment operator called " << std::endl;
    StockEnt = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return StockEnt; 
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	StockEnt = raw;
}