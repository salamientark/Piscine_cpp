/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:48 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 13:40:32 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base::~Base()
{

}

Base*	generate( void )
{
	static bool	seed = false;
	if (!seed)
	{

		std::srand(std::time(NULL));
		seed = true;
	}

	int	r = rand() % 3;
	switch (r) {
		case 0 :
			return (dynamic_cast<Base*>(new A));
			break ;
		case 1 :
			return (dynamic_cast<Base*>(new B));
		case 2 :
			return (dynamic_cast<Base *>(new C));
			break ;
		default :
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (p == NULL)
	{
		std::cerr << "idetify(Base *p) : NULL ptr" << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		return ;
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::bad_cast& bc) { }
	try {
		B& a = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)a;
	}
	catch (std::bad_cast& bc) { }
	try {
		C& a = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)a;
	}
	catch (std::bad_cast& bc) { }
}
