#include "Fixed.hpp"
#include <iostream>

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// Custom
	// Fixed	p(1.0154524365f);
	// Fixed	o(45236.389678921658f);
	// Fixed	i(0.99759999f);
	// Fixed	u(-1.0f);
	// Fixed	w(-0.5666666f);
	// Fixed	y(-0.99999999f);
	// Fixed	e(-1.034715f);
	//
	// std::cout << std::dec;
	// std::cout << "p is " << p << std::endl;
	// std::cout << "p is " << p.toInt() << " as integer" << std::endl;
	// std::cout << "p is " << std::hex << p.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "o is " << o << std::endl;
	// std::cout << "o is " << o.toInt() << " as integer" << std::endl;
	// std::cout << "o is " << std::hex << o.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "i is " << i << std::endl;
	// std::cout << "i is " << i.toInt() << " as integer" << std::endl;
	// std::cout << "i is " << std::hex << i.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "u is " << u << std::endl;
	// std::cout << "u is " << u.toInt() << " as integer" << std::endl;
	// std::cout << "u is " << std::hex << u.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "w is " << w << std::endl;
	// std::cout << "w is " << w.toInt() << " as integer" << std::endl;
	// std::cout << "w is " << std::hex << w.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "y is " << y << std::endl;
	// std::cout << "y is " << y.toInt() << " as integer" << std::endl;
	// std::cout << "y is " << std::hex << y.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "e is " << e << std::endl;
	// std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	// std::cout << "e is " << std::hex << e.toInt() << " as integer" << std::endl;
	//
	// Fixed	h(2147483646);
	// Fixed	j(2147483647);
	// Fixed	k(-2147483646);
	// Fixed	l(-2147483647);
	//
	// std::cout << std::fixed;
	// std::cout << std::dec;
	// std::cout << "h is " << h << std::endl;
	// std::cout << "h is " << h.toInt() << " as integer" << std::endl;
	// std::cout << "h is " << std::hex << h.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "j = " << j << std::endl;
	// std::cout << "j is " << j.toInt() << " as integer" << std::endl;
	// std::cout << "j is " << std::hex << j.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "k is " << k << std::endl;
	// std::cout << "k is " << k.toInt() << " as integer" << std::endl;
	// std::cout << "k is " << std::hex << k.toInt() << " as integer" << std::endl;
	//
	// std::cout << std::dec;
	// std::cout << "l = " << l << std::endl;
	// std::cout << "l is " << l.toInt() << " as integer" << std::endl;
	// std::cout << "l is " << std::hex << l.toInt() << " as integer" << std::endl;

	return 0;
}
