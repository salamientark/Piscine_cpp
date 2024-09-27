/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:35:01 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/27 18:22:53 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <string>

template< typename T >
void	print(const T& ref) {
	std::cout << "-> " << ref << std::endl;
}

int	main( void ) {

	/*
	 * empty stack
	 */
	std::cout << std::string(80, '*') << std::endl;
	std::cout << "Testing with empty MutantStack" << std::endl;
	MutantStack<int>	g;
	if (g.begin() == g.end())
		std::cout << "Stack empty" << std::endl;


	/*
	 * Filling int stack
	 */
	std::cout << std::string(80, '*') << std::endl;
	std::cout << "Testing with int filled Mutant stack" << std::endl;
	for (int i = 0; i < 10; i++) {
		g.push(i);
	}
	std::for_each(g.begin(), g.end(), print<int>);

	/*
	 * Filling string stack
	 */
	std::cout << std::string(80, '*') << std::endl;
	std::cout << "Testing with string filled Mutant stack" << std::endl;
	MutantStack<std::string>	s;
	s.push("aaa");
	s.push("bbb");
	s.push("ccc");
	s.push("ddd");
	std::for_each(s.begin(), s.end(), print<std::string>);
	std::cout << " ** reverse iterator ** " << std::endl;
	std::for_each(s.rbegin(), s.rend(), print<std::string>);

	std::cout << " ** const iterator ** " << std::endl;
	MutantStack<char>	c;

	c.push('a');
	c.push('b');
	c.push('c');
	c.push('d');
	MutantStack<char>::const_iterator cit;
	MutantStack<char>::const_iterator cend;
	for (cit = c.begin(); cit != c.end(); ++cit) {
		print<char>(*cit);
	}

	std::cout << " ** const reverse iterator ** " << std::endl;
	MutantStack<char>::const_reverse_iterator crit;
	MutantStack<char>::const_reverse_iterator crend = c.rend();
	for (crit = c.rbegin(); crit != crend; ++crit) {
		print<char>(*crit);
	}

	return (0);
}
