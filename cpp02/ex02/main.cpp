#include "Fixed.hpp"
#include <iostream>
#include <ostream>

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

	// Custom
	std::cout << "\n[ CUSTOM ]" << std::endl;
	Fixed	e(-14.4f);
	std::cout << "e = " << e << std::endl;
	Fixed	f(-14.0f);
	std::cout << "f = " << f << std::endl;
	Fixed d(3.03f);
	std::cout << "d =" << d << std::endl;
	Fixed j(-1234.4321f);
	std::cout << "j = " << j << std::endl;

	std::cout << "[ COMPARISON ]" << std::endl;
	std::cout << "max(j, f)" << Fixed::max(j, f) << std::endl;
	std::cout << "max(j, d)" << Fixed::max(j, d) << std::endl;
	std::cout << "max(e, f)" << Fixed::max(e, f) << std::endl;
	std::cout << "max(e, e)" << Fixed::max(e, e) << std::endl;
	std::cout << "min(j, f)" << Fixed::min(j, f) << std::endl;
	std::cout << "min(j, d)" << Fixed::min(j, d) << std::endl;
	std::cout << "min(e, f)" << Fixed::min(e, f) << std::endl;
	std::cout << "min(e, e)" << Fixed::min(e, e) << std::endl;

	std::cout << "[ ARITHMETIC ]" << std::endl;
	std::cout << "e + f = " << e + f << std::endl;
	std::cout << "-4 + 2 = " << Fixed(-4) + Fixed(2) << std::endl;
	std::cout << "-1 + 1 = " << Fixed(-1) + Fixed(1) << std::endl;
	std::cout << "d + e = " << d + e << std::endl << std::endl;

	std::cout << "e - f = " << e - f << std::endl;
	std::cout << "f - e = " << f - e << std::endl;
	std::cout << "-4 - 2 = " << Fixed(-4) - Fixed(2) << std::endl;
	std::cout << "-1 - 1 = " << Fixed(-1) - Fixed(1) << std::endl;
	std::cout << "-1 - -1 = " << Fixed(-1) - Fixed(-1) << std::endl;
	std::cout << "d - e = " << d - e << std::endl;
	std::cout << "d - b = " << d - b << std::endl << std::endl;

	std::cout << "-1 * 1 = " << Fixed(-1) * Fixed(1) << std::endl;
	std::cout << "-1 * -1 = " << Fixed(-1) * Fixed(-1) << std::endl;
	std::cout << "e * f = " << e * f << std::endl;
	std::cout << "(-2) * e = " << Fixed(-2) * e << std::endl;
	std::cout << "-4 * 2 = " << Fixed(-4) * Fixed(2) << std::endl;
	std::cout << "d * e = " << d * e << std::endl;
	std::cout << "d * a = " << d * a << std::endl;
	std::cout << "d * 0 = " << d * Fixed(0) << std::endl << std::endl;

	std::cout << "-1 / 1 = " << Fixed(-1) / Fixed(1) << std::endl;
	std::cout << "-1 / -1 = " << Fixed(-1) / Fixed(-1) << std::endl;
	std::cout << "e / f = " << e / f << std::endl;
	std::cout << "(-2) / e = " << Fixed(-2) / e << std::endl;
	std::cout << "-4 / 2 = " << Fixed(-4) / Fixed(2) << std::endl;
	std::cout << "d / e = " << d / e << std::endl;
	std::cout << "d / a = " << d / a << std::endl;
	// std::cout << "d / 0 = " << d / Fixed(0) << std::endl << std::endl;

	Fixed c = b / d;
	std::cout << "b / d = " << c << std::endl;

	std::cout << c << " - " << b << " = " << c - b << std::endl;

	Fixed	g(6.4f);
	Fixed	h(9.1f);
	std::cout << "g - h = " << g << " - " << h << " = " << g - h << std::endl;

	std::cout << "[ INCREMENT/DECREMENT ]" << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	std::cout << --c << std::endl;
	std::cout << c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;

	return 0;
}
