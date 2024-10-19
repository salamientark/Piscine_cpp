/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:20 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/19 14:31:09 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <cstring>
# include <exception>
# include <sstream>
# include <stdexcept>
# include <string>
# include <deque>
# include <vector>
# include <list>
# include <cmath>

class InvalidInputException : public std::exception {
	public :
		virtual const char*	what() const throw();
};

std::vector<int>	init(int ac, char **av);

void	merge_insert_sort(std::vector<int>& v, int depth);

#endif // !PMERGEME_HPP
