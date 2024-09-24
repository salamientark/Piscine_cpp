/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:43:33 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 18:19:13 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <ostream>

int	main( void )
{
	Array<int> a;
	Array<int> b(6);

	try {
		std::cout << std::string(80, '*') << std::endl
			<< "Array<int> a" << std::endl
			<< "Trying to access a[0]" <<std::endl;
		std::cout << a[0];

		std::cout << "*** SHOULD NOT APPEAR ***" << std::endl;

	}
	catch (std::exception& e) {
		std::cerr << "Out of bound access" << std::endl;
	}

	std::cout << std::endl << std::string(80, '*') << std::endl;
	std::cout << "creating a new Array<int> b" << std::endl;
	for (int i = 0; i < 6; i++) {
		b[i] = i;
		std::cout << "b[i] = " << b[i] << std::endl;
	}

	try {
		std::cout << "Try filling b[6]" << std::endl;
		b[6] = 6;

		std::cout << "*** SHOULD NOT APPEAR ***" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Out of bound access" << std::endl;
	}


	std::cout << std::endl << std::string(80, '*') << std::endl;
	std::cout << "creating different type array" << std::endl;

	Array< char >			c(3);
	Array< char >			c2(3);
	Array< std::string >	s(3);
	Array< Array< char > >  cc(2);

	c[0] = 'a';
	c[1] = 'b';
	c[2] = 'c';

	c2[0] = 'z';
	c2[1] = 'y';
	c2[2] = 'x';

	s[0] = "Yo";
	s[1] = "Yolaga";
	s[2] = "Hoy";

	cc[0] = c;
	cc[1] = c2;

	for (int i = 0; i < 3; i++) {
		std::cout << "s[" << i << "] = " << s[i] << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 2; i++) {
		std::cout << "addr cc[" << i << "] : " << &cc[0] << std::endl;
		for (int j = 0; j < 3; j++) {
			std::cout << "cc[" << i << "][" << j << "] = " << cc[i][j] << std::endl;
		}
	}

	return (0);
}
