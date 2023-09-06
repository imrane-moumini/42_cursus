#include "Fixed.hpp"


int main( void ) { 

Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;

std::cout << b << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;

return 0; 

}
// regarder vido lifetime object
// regarder comment class fonctionne under the hood
// voir pk le dernier chiffre n'est pas bon