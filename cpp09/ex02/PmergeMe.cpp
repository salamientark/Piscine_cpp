/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:49 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/11 12:53:57 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ostream>
#include <sstream>
#include <utility>

/* ************************************************************************** */
/*                                 Exception                                  */
/* ************************************************************************** */
const char*	PmergeMe::InvalidInputException::what() const throw() {
	return ("Invalid input.");
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
PmergeMe::PmergeMe( void )
	: _to_sort(std::deque<int>()), _sorted(std::list<int>())
{
	return ;
}

PmergeMe::PmergeMe( PmergeMe const & rhs )
	: _to_sort(rhs.getToSort()), _sorted(rhs.getSorted())
{
	return ;
}

PmergeMe::~PmergeMe( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::deque<int>	PmergeMe::getToSort( void ) const {
	return (this->_to_sort);
}

std::list<int>	PmergeMe::getSorted( void ) const {
	return (this->_sorted);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
PmergeMe& PmergeMe::operator=( PmergeMe const & rhs )
{
	if (this != &rhs) {
		this->_to_sort = rhs.getToSort();
		this->_sorted = rhs.getSorted();
	}
	return (*this);
}

// template < typename T >
// std::ostream& operator<<(std::ostream& os, T& rhs) {
// 	// typename T::const_iterator	it = rhs.begin();
//
// 	for (typename T::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
// 		os << " " << *it;
// 	}
// 	return (os);
// }

std::ostream&	operator<<(std::ostream& os, PmergeMe& rhs) {
	std::deque<int>	tmp = rhs.getToSort();

	for(std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
		os << " " << *it;
	}
	return (os);
}

// std::ostream&	operator<<(std::ostream& os, std::list<int> rhs) {
// 	std::list<int>::const_iterator	it = rhs.begin();
// 	std::list<int>::const_iterator	end = rhs.end();
//
// 	for(std::list<int>::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
// 		os << " " << *it;
// 	}
// 	return (os);
// }

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	PmergeMe::init(const int& ac, char** av) {
	int					tmp;
	char				c;
	std::stringstream	s;

	for (int i = 1; i < ac; i++) {
		s.clear();
		s.str(std::string(av[i]));
		if (!(s >> tmp))
			throw (PmergeMe::InvalidInputException());
		if (s >> c)
			throw (PmergeMe::InvalidInputException());
		this->_to_sort.push_back(tmp);
	}
}

template< typename T >
void	PmergeMe::sort(T& to_sort, int depth) {
	std::deque< std::deque<T> >		res;
	int								step = (1 << depth);
	std::deque<int>::const_iterator	base_it = this->_to_sort.begin() + step - 1;
	
	if (base_it == this->_to_sort.end())
		return ;
	// perform swap
	for (typename T::iterator it = to_sort.begin(); it != to_sort.end(); ++it) {
		if (base_it + step != this->_to_sort.end() && *base_it > *(base_it + step))
			std::swap(it, it + 1);
		else
			it++;
		if (it != to_sort.end())
			res.push_back(std::deque<T>(*(it - 1), *it)); // make pair
	}
	PmergeMe::sort(res, depth + 1);
}

void	PmergeMe::sort( void ) {
	this->sort(this->_to_sort, 0);
}

/* ************************************************************************** */
/*                                  Printer                                   */
/* ************************************************************************** */
// template< typename T >
// void	print(std::ostream& os, const std::deque<T>& rhs) {
// 	for (typename std::deque<T>::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
// 		Printer<T>::print(os, *it);
// 	}
// }
//
// template< typename T >
// std::ostream&	operator<<(std::ostream& os, const T& rhs) {
// 	Printer<T>::print(os, rhs);
// 	return (os);
// }
