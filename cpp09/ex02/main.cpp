/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:50:53 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/19 14:31:42 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <iostream>

int	main(int ac, char *av[]) {

	if (ac == 1) {
		std::cerr << "Error: no argument." << std::endl;
		return (0);
	}
	std::vector<int>	v;
	std::list<int>		l;
	// Initialize vector and list form argument
	try {
		int					tmp;
		char				c;
		std::stringstream	s;

		for (int i = 1; i < ac; i++) {
			s.clear();
			s.str(std::string(av[i]));
			if (!(s >> tmp))
				throw (InvalidInputException());
			if (s >> c)
				throw (InvalidInputException());
			v.push_back(tmp);
			// l.push_back(tmp);
		}
	}
	catch (InvalidInputException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	// print vector
	std::cout << "Before with std::vector<int> : ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it;
		if (it + 1 != v.end())
			std::cout << " ";
	}
	std::cout << std::endl;
	// Print list
	std::cout << "Before with std::list<int> : ";
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// sort
	std::cout << "sort" << std::endl;
	merge_insert_sort(v, 0);

	// Print after sort
	std::cout << std::endl;
	// std::cout << "After : ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it;
		if (it + 1 != v.end())
			std::cout << " ";
	}
	std::cout << std::endl;


	return (0);
}
