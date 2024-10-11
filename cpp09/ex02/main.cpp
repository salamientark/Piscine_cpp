/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:50:53 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/11 12:33:35 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <iostream>

int	main(int ac, char *av[]) {

	if (ac == 1) {
		std::cerr << "Error: no argument." << std::endl;
	}
	PmergeMe	p;
	try {
		p.init(ac, av);
	}
	catch (PmergeMe::InvalidInputException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "p : {" << p << " }" << std::endl;
	p.sort(p.getToSort(), 0);

	return (0);
}
