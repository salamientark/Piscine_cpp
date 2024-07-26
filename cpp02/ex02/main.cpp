#include "Fixed.hpp"
#include <iostream>

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

	Fixed	e(-14.4f);
	std::cout << "e = " << e << std::endl;
	Fixed	f(-14.0f);
	std::cout << "f = " << f << std::endl;

	Fixed d(3.03f);
	std::cout << d << std::endl;

	Fixed c = b / d;
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;

	std::cout << c << " - " << b << " = " << c - b << std::endl;

	Fixed	g(6.4f);
	Fixed	h(9.1f);
	std::cout << "g - h = " << g << " - " << h << " = " << g - h << std::endl;

	return 0;
}
