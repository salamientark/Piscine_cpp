/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:09:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 21:26:26 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int	main( void )
{
	/*
	 * Testing with empty contaitiner
	 */
	std::cout << std::string(80, '*') << std::endl;
	std::cout << "Testing with empty container v" << std::endl;
	std::vector<int>	v;
	try {
		easyfind(v, 3);
	}
	catch (std::exception& e) {
		std::cerr << "easyfind couldn't find value" << std::endl;
	}
	
	/*
	 * Normal test
	 */
	std::cout << std::endl << std::string(80, '*') << std::endl;
	std::cout << "Testing with few_value in vector" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "v.push_back(" << i << ")" << std::endl;
		v.push_back(i);
	}
	std::cout << "easyfind(v, 3) = " << easyfind(v, 3) << std::endl;

	/*
	 * Testing with const list
	 */
	std::list<int>	l;
	std::cout << std::endl << std::string(80, '*') << std::endl;
	std::cout << "Testing with few_value const_list" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "l.push_back(" << i << ")" << std::endl;
		l.push_back(i);
	}
	std::cout << "easyfind(l, 4) = " << easyfind(l, 4) << std::endl;

	/*
	 * Testing with dequeu 
	 */
	std::deque<int>	d;
	std::cout << std::endl << std::string(80, '*') << std::endl;
	std::cout << "Testing with few_value const_list" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "d.push_back(" << i << ")" << std::endl;
		d.push_back(i);
	}
	std::cout << "easyfind(d, 1) = " << easyfind(d, 1) << std::endl;
	

}
