#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <ostream>

int main( void ) {
	Point	a(Fixed(-1.2f), Fixed(-1.5f));
	Point	b(Fixed(1.8f), Fixed(-1.003f));
	Point	c(Fixed(0), Fixed(1));

	Point	p(Fixed(0), Fixed(0));

	std::cout << "Is the point P inside the triangle made by the point A, B, C ?" << std::endl;
	std::cout << "A = { " << a.getXCoord() << " ; " << a.getYCoord() << " }" << std::endl;
	std::cout << "B = { " << b.getXCoord() << " ; " << b.getYCoord() << " }" << std::endl;
	std::cout << "C = { " << c.getXCoord() << " ; " << c.getYCoord() << " }" << std::endl << std::endl;
	std::cout << "P = { " << p.getXCoord() << " ; "  << p.getYCoord() << " }" << std::endl << std::endl;

	// for (Fixed i = Fixed(-1); i < Fixed(2); i = i + Fixed(0.25f))
	// {
	// 	for (Fixed j = Fixed(-1); j < Fixed(2); j = j + Fixed(0.25f))
	// 	{
	// 		std::cout << "{ " << std::setw(16) << i << " ; " << std::setw(16) << j << " }";
	// 		Point	tmp(i, j);
	// 		if (is_point_inside_triangle(tmp, a, b, c) == true)
	// 			std::cout << " Inside" << std::endl;
	// 		else
	// 			std::cout << " NOT Inside" << std::endl;
	// 	}
	// }

	return 0;
}
