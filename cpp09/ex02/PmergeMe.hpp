/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:20 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/11 22:49:34 by dbaladro         ###   ########.fr       */
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

class InvalidInputException : public std::exception {
	public :
		virtual const char*	what() const throw();
};

std::vector<int>	init(int ac, char **av);

void	sort(std::vector<int>& v, int depth);

#endif // !PMERGEME_HPP
