#include "Fixed.hpp"

Fixed::Fixed(){
    StockEnt = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nbr){
    std::cout << "Int constructor called" << std::endl;
    StockEnt = nbr << NbrBytesFr;

}

Fixed::Fixed(const float  nbr){
    std::cout << "Float constructor called" << std::endl;
    StockEnt = roundf(nbr * (1 << NbrBytesFr));

}

Fixed::Fixed(const Fixed& rhs){
    std::cout << "Copy constructor called" << std::endl;
    StockEnt = rhs.getRawBits();
}


Fixed& Fixed::operator=(const Fixed& rhs){
    std::cout << "Copy assignment operator called " << std::endl;
    StockEnt = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    //std::cout << "getRawBits member function called" << std::endl;
    return StockEnt; 
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	StockEnt = raw;
}

float Fixed::toFloat() const {

    return (float)StockEnt/ (1 << NbrBytesFr); 
}

int Fixed::toInt() const {
    return StockEnt >> NbrBytesFr; 
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}