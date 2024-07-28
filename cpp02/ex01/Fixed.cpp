/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:04:42 by madlab            #+#    #+#             */
/*   Updated: 2024/07/28 19:27:58 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <ios>
#include <iostream>
#include <ostream>
#include <cstdlib>

Fixed::Fixed( void ) : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int nbr )
{
	std::cout << "Int constructor was called" << std::endl;
	std::cout << std::hex << nbr  << std::endl;
	if ((nbr & 0x80000000) == 0) // Positive nbr
		this->_nbr = ((nbr << 8) & 0x7FFFFFFF);
	else
		this->_nbr = ((nbr << 8) | 0x8000000);
	std::cout << std::hex << this->_nbr << std::endl;
	return ;
}

Fixed::Fixed( const float nbr )
{
	std::cout << "Float constructor called" << std::endl;
	this->_nbr = (round(nbr * (1 << Fixed::_fractBitNbr)));

	return ;
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
	char	sign = (this->_nbr & 0x80000000);
	int		nbr_cp = ((this->_nbr & 0x80000000) != 0 ? ((this->_nbr ^ 0xFFFFFFFF) >> 8) + 1 : this->_nbr >> 8);
	float	result = (float)nbr_cp;
	int		mask = 128;
	float	ref = 0.5f;

	for (int i = 0; i < 8; i++)	
	{
		result += (ref * ((mask & this->_nbr) > 0));
		ref /= 2;
		mask = (mask >> 1);
	}
	if (sign == 0)
		return (result);
	return (-result);
}

int		Fixed::toInt( void ) const
{
	if ((this->_nbr & 0x80000000) == 0) // Positive
		return ((this->_nbr >> 8));
	return ((this->_nbr >> 8) | 0xFF000000);
}
