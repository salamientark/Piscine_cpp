/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:20 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/11 12:48:13 by dbaladro         ###   ########.fr       */
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
# include <list>

class PmergeMe {
public:
	class InvalidInputException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
	PmergeMe( void );
	PmergeMe( PmergeMe const & rhs );
	~PmergeMe();

	PmergeMe&		operator=( PmergeMe const & rhs );

	std::deque<int>	getToSort( void ) const;
	std::list<int>	getSorted( void ) const;

	void			init(const int& ac, char *av[]);

	template< typename T >
	void			sort(T& to_sort, int depth);
	void			sort( void );

private:
	std::deque<int>	_to_sort;
	std::list<int>	_sorted;
	
};

/* ************************************************************************** */
/*                                  Printer                                   */
/* ************************************************************************** */
std::ostream&	operator<<(std::ostream& os, PmergeMe& rhs);

#endif // !PMERGEME_HPP
