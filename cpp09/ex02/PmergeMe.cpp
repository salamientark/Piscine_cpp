/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:49 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/15 09:56:53 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <ostream>
#include <sstream>
#include <iostream>

/* ************************************************************************** */
/*                                 Exception                                  */
/* ************************************************************************** */
const char*	InvalidInputException::what() const throw() {
	return ("Invalid input.");
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	sort(std::vector<int>& v, int depth) {
	int	step = (1 << depth);	// define iterator step
	
	if (v.size() / step < 2)	// only one element in list of size 2^step
		return ;				// end recursion

	std::vector<int>::iterator	end = ((v.size() / step) % 2 ? v.begin() + (v.size() / step) * step - 1 : v.end() - 1);

	// Perform swap
	for (std::vector<int>::iterator it = v.begin() + step - 1; it < end && it != v.end(); it += step) {
		if (it + step != v.end() && *(it + step) < *it)
			std::swap_ranges(it + 1 - step, it + 1, it + 1);
		// else
		// 	it += step;
		it += step;
	}

	// PRINT STATUS FOR TESTING PURPOSE
	std::cout << "Sorting depth = " << depth << " : ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it;
		if (it + 1 != v.end())
			std::cout << " ";
	}
	std::cout << std::endl;

	sort(v, depth + 1); // Perform recursion
	
	// Perform insertion part
}

/* ************************************************************************** */
/*                                  Printer                                   */
/* ************************************************************************** */
