/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:20 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/19 15:05:01 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <exception>
# include <sstream>
# include <deque>
# include <vector>
# include <cmath>

class InvalidInputException : public std::exception {
	public :
		virtual const char*	what() const throw();
};

void	sort(std::vector<int>& v, int depth);
void	sort(std::deque<int>& v, int depth);

/* ************************************************************************** */
/*                                   TEMPLATED                                */
/* ************************************************************************** */
// template< typename T >
// void	sort(T& v, int depth) {
// 	if (v.size() / (1 << depth) < 2)	// only one element in list of size 2^step
// 		return ;						// end recursion
//
// 	// define first 32 jacobstahl term
// 	static const int	jacobsthal[32] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341,
// 		683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 
// 		699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
// 		89478485, 178956971, 357913941, 715827883, 1431655765};
//
// 	/* ----------   SWAP PART   ---------*/
// 	unsigned long			step = (1 << depth);	// define iterator step
// 	typename T::iterator	v_it, end = ((v.size() / step) % 2 ? v.begin() + (v.size() / step) * step - 1 : v.end() - 1);
//
// 	// Perform swap
// 	for (v_it = v.begin() + step - 1; v_it < end && v_it != v.end(); v_it += step) {
// 		if (v_it + step != v.end() && *(v_it + step) < *v_it)
// 			std::swap_ranges(v_it + 1 - step, v_it + 1, v_it + 1);
// 		v_it += step;
// 	}
//
// 	sort(v, depth + 1); // step up pair len
//
// 	/* ----------   INSERT PART   ---------*/
// 	int						jacob_idx = 1; // Jacobsthal index
// 	int						diff;			// Jacobstahal diff
// 	int						res_len = step * (std::floor((v.size()/ (2.0 * step)) - 1) + 2);
// 	T						main(v.size()), to_insert(((v.size() - res_len) / step) * step);
// 	typename T::iterator	res_it, to_insert_it; // T iterator
// 	typename T::iterator	d_lim, h_lim, pos; // binary search variable
//
// 	if (to_insert.size() == 0)
// 		return ;
//
// 	// Init the main_chain and the pair_chain T
// 	std::copy(v.begin(), v.begin() + 2 * step, main.begin());
// 	v_it = v.begin() + 2 * step;
// 	res_it = main.begin() + 2 * step;
// 	to_insert_it = to_insert.begin();
// 	while (v_it != v.end()) {
// 		if (v_it + step > v.end())
// 			break ;
// 		std::copy(v_it, v_it + step, to_insert_it);
// 		to_insert_it += step;
// 		v_it += step;
// 		if (v_it + step > v.end())
// 			break ;
// 		std::copy(v_it, v_it + step, res_it);
// 		res_it += step;
// 		v_it += step;
// 	}
//
// 	// Set to first pair to insert
// 	pos = to_insert.begin() + jacobsthal[jacob_idx] * step - 1;
// 	while (std::distance(to_insert.begin(), pos) < static_cast<long int>(v.size())) {
// 		// Perform insertion following jacobsthal order
// 		diff = 0;
// 		for (pos = pos; pos >= to_insert.begin() + jacobsthal[jacob_idx - 1] * step; pos -= step) {
// 			// Prepare For binary search
// 			d_lim = main.begin() + step - 1; // Set down limit
// 			h_lim = main.begin() + res_len - 1;
// 			res_it = d_lim + std::floor((std::distance(d_lim, h_lim) / step) / 2) * step;
// 			do {
// 				if (*pos < *res_it) {
// 					h_lim = res_it;
// 					res_it -= std::ceil(((static_cast<float>(std::distance(d_lim, h_lim)) / step) / 2.0)) * step;
// 					if (!(res_it <= d_lim))
// 						continue;
// 					res_it = d_lim;
// 					break ;
// 				}
// 				if (*pos > *(res_it + step)) {
// 					d_lim = res_it;
// 					if (res_it + step == h_lim)
// 						res_it = h_lim;
// 					else
// 						res_it += std::ceil(((static_cast<float>(std::distance(d_lim, h_lim)) / step) / 2.0)) * step;
// 					if (!(res_it >= h_lim))
// 						continue;
// 					res_it = h_lim;
// 					break ;
// 				}
// 				break ;
// 			} while ( pos != d_lim );
// 			if (*pos > *res_it)
// 				res_it += step;
// 			// Insert
// 			std::copy_backward(res_it + 1 - step, main.end() - step, main.end()); // Move element
// 			std::copy(pos + 1 - step, pos + 1, res_it - step + 1);
// 			diff++;
// 			res_len += step;
// 		}
// 		jacob_idx++;
// 		// Check if there are still value to insert
// 		if (std::distance(to_insert.begin(), to_insert.begin() + (jacobsthal[jacob_idx - 1] + 1) * step - 1) >= static_cast<long int>(to_insert.size()))
// 			break ;
// 		pos = std::min(to_insert.end() - 1, to_insert.begin() + jacobsthal[jacob_idx] * step - 1);
//
// 	}
// 	// Add uninserted part if one
// 	if (v.size() % (2 * step) != 0) {
// 		std::copy(v.end() - (v.size() % step), v.end(), main.end() - (v.size() % step));
// 	}
// 	v = main;
// 	return ;
// }

#endif // !PMERGEME_HPP
