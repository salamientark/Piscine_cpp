/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:04:42 by madlab            #+#    #+#             */
/*   Updated: 2024/07/22 09:00:22 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>

Fixed::Fixed( void ) : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int nbr ) : _nbr((nbr << 8))
{
	std::cout << "Int constructor was called" << std::endl;
}

Fixed::Fixed( const float nbr )
{
	float	floating_part;
	int		converted_nbr = 0;
	float	ref = 0.5f;

	std::cout << "Float constructor called" << std::endl;
	this->_nbr = (int)nbr;
	this->_nbr = (this->_nbr << 8);
	floating_part = (nbr - (int)nbr);
	for (int i = 0; i < 7; i++)
	{
		if (floating_part > ref)
		{
			converted_nbr++;
			floating_part -= ref;
		}
		ref /= 2;
		converted_nbr = (converted_nbr << 1);
	}
	this->_nbr = (this->_nbr | converted_nbr);
}

Fixed::Fixed( Fixed const & rhs )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

// OPERATOR OVERLOAD
Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nbr = rhs.getRawBits();
	return (*this);
}

std::ostream &	operator<<( std::ostream & os, const Fixed & rhs )
{
	os << rhs.toFloat();
	return (os);
}

// GETTER AND SETTERS
int		Fixed::getRawBits( void ) const
{
	return (this->_nbr);
}

void	Fixed::setRawBits( int const raw )
{
	this->_nbr = raw;
}

// Public Memeber functions
float	Fixed::toFloat( void ) const
{
	float	result;
	int		mask = 128;
	float	ref = 0.5f;

	result = (float)(this->_nbr >> 8);
	for (int i = 0; i < 8; i++)	
	{
		result += (ref * ((mask & this->_nbr) > 0));
		ref /= 2;
		mask = (mask >> 1);
	}
	return (result);
}

int		Fixed::toInt( void ) const
{
	return ((this->_nbr >> 8));
}
