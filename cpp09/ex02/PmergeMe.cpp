/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:49 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/18 23:49:30 by dbaladro         ###   ########.fr       */
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


void new_insert(std::vector<int>& v, int depth) {
	// Perform insertion part
	// define first 32 jacobstahl term
	static const int	jacobsthal[32] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341,
		683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 
		699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
		89478485, 178956971, 357913941, 715827883, 1431655765};

	unsigned long int	step = (1 << depth);	// define iterator step
	int	jacob_idx = 1; // Jacobsthal index
	int	diff;			// Jacobstahal diff

	std::vector<int>::iterator	d_lim, h_lim, pos; // binary search variable
	std::vector<int>::iterator	v_it, res_it, to_insert_it, end, a; // vector iterator
	// std::vector<int>			res(v.size()), to_insert(v.size() / 2); // tmp vector when inserting
	std::vector<int>			res(v.size()), to_insert(std::ceil(((v.size() - 2 * step) /  step) / 2.0) * step);

	// Fill the res and to insert vector
	std::copy(v.begin(), v.begin() + 2 * step, res.begin());
	v_it = v.begin() + 2 * step;
	res_it = res.begin() + 2 * step;
	to_insert_it = to_insert.begin();
	while (v_it != v.end()) {
		if (v_it + step > v.end())
			break ;
		std::copy(v_it, v_it + step, to_insert_it);
		to_insert_it += step;
		v_it += step;
		if (v_it + step > v.end())
			break ;
		std::copy(v_it, v_it + step, res_it);
		res_it += step;
		v_it += step;
	}
	// Finished copy Lets insert

	// INSERT
	pos = to_insert.begin() + jacobsthal[jacob_idx] * step - 1; // Set to first pair to insert
	
	while (std::distance(to_insert.begin(), pos) < static_cast<long int>(v.size())) {
	// while (std::distance(to_insert.begin(), to_insert.begin() + jacobsthal[jacob_idx] * step) < static_cast<long int>(v.size())) {
	
		// Perform insertion following jacobsthal order
		diff = 0;
		for (pos = pos; pos >= to_insert.begin() + jacobsthal[jacob_idx - 1] * step; pos -= step) {

			// Prepare For binary search
			d_lim = res.begin() + step - 1; // Set down limit
			h_lim = res.end() - 1 - (to_insert.size() - (pos - to_insert.begin())) * step;
			// h_lim = res.begin() + 2 * step - 1 + ((v.size() - 2 * step) / 2) / step + diff;

			res_it = d_lim + (std::distance(d_lim, h_lim) / step) / 2;
			// res_it = res.begin() + std::ceil((std::distance(d_lim, h_lim) / step) / 2);
			// if (std::distance(d_lim, h_lim) == static_cast<long int>(step))
			// 	res_it = d_lim;
			do {
				if (*pos < *res_it) {
					h_lim = res_it;
					res_it -= std::ceil((std::distance(d_lim, h_lim) / step) / 2.0);
					if (res_it < d_lim) {
						res_it = d_lim;
						break ;
					}
					continue;
				}
				if (*pos > *(res_it + step)) {
					d_lim = res_it;
					if (res_it + step == h_lim)
						res_it = h_lim;
					else
						res_it += std::ceil((std::distance(d_lim, h_lim) / step) / 2);
					// res_it += std::ceil(std::distance(d_lim, h_lim) / 2.0) * step;
					if (res_it >= h_lim) {
						res_it = h_lim;
						break ;
					}
					continue;
				}
				break ;
			} while ( std::distance(d_lim, h_lim) / step > 1 );
			// if (res_it != h_lim && *pos > *res_it)
			if (*pos > *res_it)
				res_it += step;

			// std::copy_backward(res_it, res.end() - (res_it - res.begin()), res.end()); // Move element
			std::copy_backward(res_it + 1 - step, res.end() - step, res.end()); // Move element
			std::copy(pos + 1 - step, pos + 1, res_it - step + 1);

			diff++;
		}
		jacob_idx++;
		// SIZE CHECK IS FALSE BECAUS EWE ALLOCATED TO MUCH
		if (std::distance(to_insert.begin(), to_insert.begin() + jacobsthal[jacob_idx - 1] * step - 1) >= static_cast<long int>(to_insert.size()))
		// if (std::distance(to_insert.begin(), to_insert.begin() + (jacobsthal[jacob_idx - 1] + 1) * step - 1) >= static_cast<long int>(to_insert.size()))
			break ;

		pos = std::min(to_insert.end() - 1, to_insert.begin() + jacobsthal[jacob_idx] * step - 1);

	}
	// Add uninserted part if one
	if (v.size() % (2 * step) != 0) {
		std::copy(v.end() - (v.size() % step), v.end(), res.end() - (v.size() % step));
	}
	v = res;
	return ;
}

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
		while (it - diff > v.begin() + jacobsthal[jacob_idx] * step + step - 1) {
		// for (std::vector<int>::iterator j = it; std::distance(v.begin(), j) > std::distance(v.begin(), v.begin() + jacobsthal[jacob_idx]  * step + step - 1); j -= 2 * step) {
			std::vector<int>::iterator	j = it - diff;

			std::copy(j - step / 2, j + 1, tmp.begin()); // Save vector to insert

			// Perform binary search
			d_lim = v.begin()+ step - 1; // set down limit

			// h_lim = j;
			h_lim = j;

			pos = v.begin() + (((std::distance(v.begin(), h_lim) / step) + 1) / 2 ) * step + step - 1; do {
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
			diff += 2 * step;
			if (pos <= it - diff)
				diff -= step;
			// j += (pos < j - 1) * step;
		}
		// Finished part of insertion following jacosthal
		it = v.begin() + (jacobsthal[jacob_idx]) * 2 * step  + step - 1;

		if (std::distance(v.begin(), it + step) >= static_cast<long int>(v.size()))
			break ;
		jacob_idx++;

		for (int a = jacobsthal[jacob_idx] - jacobsthal[jacob_idx - 1]; a > 0; --a) {
			if (std::distance(v.begin(), it + 2 * step) >= static_cast<long int>(v.size()))
				break ;
			it += 2 * step;
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

	sort(v, depth + 1); // Perform recursion
	
					/* ----------------------------------------- */


	// for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
	// 	std::cout << *it;
	// 	if (it + 1 != v.end())
	// 		std::cout << " ";
	// }
	// std::cout << std::endl;


	// Perform insertion part
	new_insert(v, depth);

	return ;
}

/* ************************************************************************** */
/*                                  Printer                                   */
/* ************************************************************************** */
