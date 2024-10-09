/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:50:53 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/03 11:53:54 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char *av[]) {

	std::deque<int> q(1, 2);
	std::cout << q << std::endl;
	if (ac == 1) {
		std::cerr << "Error: no argument." << std::endl;
	}
	return (0);
}
