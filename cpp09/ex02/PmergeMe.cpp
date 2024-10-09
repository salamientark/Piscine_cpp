/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:40:49 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/03 12:57:05 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <strstream>

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

std::ostream&	operator<<(std::ostream& os, std::deque<int> rhs) {
	std::deque<int>::const_iterator	it = rhs.begin();
	std::deque<int>::const_iterator	end = rhs.end();

	for(std::deque<int>::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
		os << " " << *it;
	}
	return (os);
}

std::ostream&	operator<<(std::ostream& os, std::list<int> rhs) {
	std::list<int>::const_iterator	it = rhs.begin();
	std::list<int>::const_iterator	end = rhs.end();

	for(std::list<int>::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
		os << " " << *it;
	}
	return (os);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	PmergeMe::addDeque(const int& ac, char* av[]) {
	int					tmp;
	char				c;
	std::stringstream	s;

	for (int i = 1; i < ac; i++) {
		s = std::stringstream(av[i]);
		if (!(s >> tmp))
			throw (PmergeMe::InvalidInputException());
		if (s >> c)
			throw (PmergeMe::InvalidInputException());
		this->_to_sort.push_back(tmp);
	}
}
