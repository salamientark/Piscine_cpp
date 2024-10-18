/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:49 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/18 12:19:14 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ostream>
#include <sstream>
#include <iostream>
#include <vector>

/* ************************************************************************** */
/*                                 Exception                                  */
/* ************************************************************************** */
const char*	InvalidInputException::what() const throw() {
	return ("Invalid input.");
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */

void	insert(std::vector<int>& v, int depth) {
	// Perform insertion part
	// define first 32 jacobstahl term
	static const int	jacobsthal[32] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341,
		683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 
		699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
		89478485, 178956971, 357913941, 715827883, 1431655765};

	int	step = (1 << depth);	// define iterator step
	int	jacob_idx = 1; // Jacobsthal index
	int	diff;			// Jacobstahal diff

	std::vector<int>::iterator	d_lim, h_lim, pos; // binary search variable
	std::vector<int>::iterator	it, end, a; // vector iterator
	std::vector<int>			tmp(step); // tmp vector when inserting

	// This keep the vector of size two by trying to go to the third element
	it = v.begin() + 3 * step - 1; // go to third element directly

	while (static_cast<long unsigned int>(std::distance(v.begin(), it)) < v.size()) {

	
		// set it to the first element to insert 
		diff = 0;
		for (std::vector<int>::iterator j = it; std::distance(v.begin(), j) > std::distance(v.begin(), v.begin() + jacobsthal[jacob_idx]  * step + step - 1); j -= 2 * step) {

			std::copy(j - step / 2, j + 1, tmp.begin()); // Save vector to insert

			// Perform binary search
			d_lim = v.begin()+ step - 1; // set down limit

			h_lim = j;

			pos = v.begin() + (((std::distance(v.begin(), h_lim) / step) + 1) / 2 ) * step + step - 1;
			do {
				if (*tmp.rbegin() < *pos) {
					h_lim = pos;
					// pos -= std::ceil(std::distance(d_lim, h_lim) / 2.0) * step;
					pos -= std::ceil(std::distance(d_lim, h_lim) / 2.0);
					if (std::distance(d_lim, pos) < step) {
						pos = d_lim;
						break ;
					}
					continue;
				}
				if (*tmp.rbegin() > *(pos + step)) {
					d_lim = pos;
					pos += std::ceil((std::distance(d_lim, h_lim) + 1) / 2.0) * step;
					if (pos > h_lim) {
						pos = h_lim;
						break ;
					}
					continue;
				}
				break ;
			} while (pos != v.begin());
			if (*pos < *j)
				pos += step;

			// move
			if (pos != j) {
				std::copy_backward(pos - step + 1, j - step + 1, j + 1);
				std::copy(tmp.begin(), tmp.end(), pos - step + 1);
			}

			// insert
			diff++;
			j += (pos < j - 1);
		}
		// Finished part of insertion following jacosthal
		it = v.begin() + (jacobsthal[jacob_idx] + 1) * 2 * step + step - 1;
		if (std::distance(v.begin(), it) >= static_cast<long int>(v.size()))
			break ;
		jacob_idx++;

		for (int a = jacobsthal[jacob_idx] - jacobsthal[jacob_idx - 1]; a > 0; --a) {
			if (std::distance(v.begin(), it + 2 * step) >= static_cast<long int>(v.size())) {
				break ;
			it += 2 * step;
			}
		}
	}

}

void	sort(std::vector<int>& v, int depth) {
	int	step = (1 << depth);	// define iterator step
	
	if (v.size() / step < 2)	// only one element in list of size 2^step
		return ;				// end recursion

	std::vector<int>::iterator	it, end = ((v.size() / step) % 2 ? v.begin() + (v.size() / step) * step - 1 : v.end() - 1);

	// Perform swap
	for (it = v.begin() + step - 1; it < end && it != v.end(); it += step) {
		if (it + step != v.end() && *(it + step) < *it)
			std::swap_ranges(it + 1 - step, it + 1, it + 1);
		it += step;
	}

	// PRINT STATUS FOR TESTING PURPOSE
	// std::cout << "Sorting depth = " << depth << " : ";
	// for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
	// 	std::cout << *it;
	// 	if (it + 1 != v.end())
	// 		std::cout << " ";
	// }
	// std::cout << std::endl;

	sort(v, depth + 1); // Perform recursion
	
					/* ----------------------------------------- */


	// for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
	// 	std::cout << *it;
	// 	if (it + 1 != v.end())
	// 		std::cout << " ";
	// }
	// std::cout << std::endl;


	// Perform insertion part
	insert(v, depth);

	return ;
}

/* ************************************************************************** */
/*                                  Printer                                   */
/* ************************************************************************** */
