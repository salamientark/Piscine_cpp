/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:30:28 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/25 01:05:07 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char*	Span::SpanTooSmallException::what() const throw() {
	return ("Span too small.");
}

const char*	Span::SpanMaxSizeReachedException::what() const throw() {
	return ("max_capacity reached");
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Span::Span( void ) : _max_size(0), _v(std::vector<int>())
{
	return ;
}

Span::Span( const unsigned int max_size )
	: _max_size(max_size), _v(std::vector<int>())
{
	return ;
}

Span::Span( Span const & rhs )
	: _max_size(rhs.getMaxSize())
{
	this->_v = std::vector<int>(rhs.getV().size());
	std::copy(rhs.getV().begin(), rhs.getV().end(), this->_v.begin());
	return ;
}
Span::~Span( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
unsigned int	Span::getMaxSize( void ) const
{
	return (this->_max_size);
}

std::vector<int>	Span::getV( void ) const
{
	return (this->_v);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Span& Span::operator=( Span const & rhs )
{
	if (this == &rhs)
		return (*this);
	this->_max_size = rhs.getMaxSize();
	std::copy(rhs.getV().begin(), rhs.getV().end(), this->_v.begin());
	return (*this);
}


/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	Span::addNumber( int nbr )
{
	try {
		if (this->_max_size == this->_v.size())
			throw (Span::SpanMaxSizeReachedException());
		this->_v.push_back( nbr );
	}
	catch (std::exception& e) {
		std::cerr << "Span::addNumber : " << std::endl;
	}
}

/*
 * Return the smallest spawn
 * If the smallest value is present two or more in the Span it will return 0
 */
int	Span::shortestSpan( void ) const
{
	if (this->_max_size <= 1 || this->_v.size() <= 1)
		throw (Span::SpanTooSmallException());

	std::vector<int>::const_iterator	ref = std::min_element(this->_v.begin(), this->_v.end());
	int									span = std::abs(this->_v[0] - this->_v[1]);

	for (std::vector<int>::const_iterator it = this->_v.begin() + 1; it != this->_v.end(); ++it){
		if (it != ref)
			span = std::min(span, std::abs(*ref - *it));
	}
	if (span > 0)
		span--;
	return (span);
}

/*
 * Return the longest spawn
 * If the biggest value is present two or more in the Span it will return 0
 */
int	Span::longestSpan( void ) const
{
	if (this->_max_size <= 1 || this->_v.size() <= 1)
		throw (Span::SpanTooSmallException());
	std::vector<int>::const_iterator	ref = std::max_element(this->_v.begin(), this->_v.end());
	int									span = std::abs(this->_v[0] - this->_v[1]);

	for (std::vector<int>::const_iterator it = this->_v.begin() + 1; it != this->_v.end(); ++it){
		if (it != ref)
			span = std::max(span, std::abs(*ref - *it));
	}
	return (span);
}

static int generateNbr( int& val )
{
	static int	seed = false;
	if (seed == false)
	{
		srand(time(NULL));
		seed = true;
	}
	val = rand() % 1000000;
	return (rand());
}

void	Span::fillSpan( void )
{
	this->_v.resize(this->_max_size);
	std::for_each(this->_v.begin(), this->_v.end(), generateNbr);
}
