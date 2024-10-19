/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:50:53 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/19 15:14:08 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>

int	main(int ac, char *av[]) {

	if (ac == 1) {
		std::cerr << "Error: no argument." << std::endl;
		return (0);
	}

	std::vector<int>	v;
	std::deque<int>		d;
	int vector_clock, deque_clock;

	// Initialize vector and deque form argument
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
			d.push_back(tmp);
		}
	}
	catch (InvalidInputException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	// print vector
	std::cout << "Before : ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it;
		if (it + 1 != v.end())
			std::cout << " ";
	}
	std::cout << std::endl;

	// sort
	vector_clock = std::clock();
	sort(v, 0);
	vector_clock = std::clock() - vector_clock;

	deque_clock = std::clock();
	sort(d, 0);
	deque_clock = std::clock() - deque_clock;

	// Print after sort
	std::cout << "After : ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it;
		if (it + 1 != v.end())
			std::cout << " ";
	}
	std::cout << std::endl;

	// Print Time consumed
	std::cout << "Time to process a range of " << std::setw(7) << ac - 1
		<< " elements with std::vector<int> : " << vector_clock << " operations."
		<< std::endl;

	std::cout << "Time to process a range of " << std::setw(7) << ac - 1
		<< " elements with std::deque<int> : " << deque_clock << " operations."
		<< std::endl;
	return (0);
}
