/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:09 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 13:35:42 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main( void )
{
	A a = A();
	B b = B();
	C c = C();

	std::cout << std::string(80, '*') << std::endl
		<< "===> Identifying using references <===" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	std::cout << std::endl;

	A* a_ptr = &a;
	B* b_ptr = &b;
	C* c_ptr = &c;
	std::cout << std::string(80, '*') << std::endl
		<< "===> Identifying using pointers <===" << std::endl;
	identify(a_ptr);
	identify(b_ptr);
	identify(c_ptr);
	identify(c_ptr);
	identify(c_ptr);
	identify(c_ptr);
	std::cout << std::endl;

	std::cout << std::string(80, '*') << std::endl
		<< "===> Testing generation <===" << std::endl;

	Base *tmp;
	for (int i = 0; i < 10; i++)
	{
		tmp = generate();
		identify(tmp);
		delete(tmp);
	}
	return (0);
}
