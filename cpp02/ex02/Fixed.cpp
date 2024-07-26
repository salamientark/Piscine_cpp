/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:04:42 by madlab            #+#    #+#             */
/*   Updated: 2024/07/22 20:20:07 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cstdlib>

// Constructor en Destructor
Fixed::Fixed( void ) : _nbr(0)
{
}

Fixed::Fixed( const int nbr ) : _nbr((nbr << 8))
{
}

// Problem is here, Doesn' t round up correctly
Fixed::Fixed( const float nbr )
{
	float	floating_part = (std::abs(nbr) - (int)std::abs(nbr));
	float	ref = 0.5f;

	this->_nbr = (int)nbr;
	this->_nbr = (this->_nbr << 1);
	for (int i = 0; i < 7; i++)
	{
		if (std::abs((double))

		if (std::abs(floating_part - ref) >= 0.00390625f && floating_part > ref)
		{
			this->_nbr = (this->_nbr | 1);
			floating_part -= ref;
		}
		if (std::abs(floating_part - ref) < 0.00390625f
			&& std::abs(floating_part - ref) < floating_part)
		{
			this->_nbr = (this->_nbr | 1);
			floating_part -= ref;
		}
		ref /= 2;
		this->_nbr = (this->_nbr << 1);
	}
	this->_nbr = (this->_nbr);
}

Fixed::Fixed( Fixed const & rhs )
{
	*this = rhs;
}

Fixed::~Fixed( void )
{
}
// Constructor and Destructor END

// OPERATOR Overload
Fixed & Fixed::operator=( Fixed const & rhs )
{
	this->_nbr = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator<( const Fixed& rhs )
{
	return (this->_nbr < rhs.getRawBits());
}

bool	Fixed::operator>( const Fixed& rhs )
{
	return (this->_nbr > rhs.getRawBits());
}

bool	Fixed::operator<=( const Fixed& rhs )
{
	return (rhs.getRawBits() > this->_nbr );
}

bool	Fixed::operator>=( const Fixed& rhs )
{
	return (rhs.getRawBits() < this->_nbr );
}

bool	Fixed::operator==( const Fixed& rhs )
{
	return (rhs.getRawBits() == this->_nbr );
}

bool	Fixed::operator!=( const Fixed& rhs )
{
	return (!(rhs.getRawBits() == this->_nbr ));
}

// operator +, -, *, /
Fixed&	Fixed::operator+( const Fixed& rhs )
{
	this->_nbr = (this->_nbr + rhs.getRawBits());
	return (*this);
}

Fixed&	Fixed::operator-( const Fixed& rhs )
{
	this->_nbr = (this->_nbr - rhs.getRawBits());
	return (*this);
}

Fixed&	Fixed::operator*( const Fixed& rhs )
{
	int	result = ((this->_nbr) * (rhs.getRawBits()));
	this->_nbr = result >> 8;
	return (*this);
}

Fixed&	Fixed::operator/( const Fixed& rhs )
{
	this->_nbr = (this->_nbr / rhs.getRawBits()); 
	// this->setRawBits( this->toFloat() / rhs.toFloat()); 
	return (*this);
}

// ++X, X++, --X, X--
Fixed&	Fixed::operator++( void )
{
	this->_nbr++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	old = *this;
	operator++();
	return (old);
}

Fixed&	Fixed::operator--( void )
{
	this->_nbr--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	old = *this;
	operator--();
	return (old);
}

// <<
std::ostream &	operator<<( std::ostream & os, const Fixed & rhs )
{
	os << rhs.toFloat();
	return (os);
}
// operator Overload END

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
		if (this->_nbr < 0)
			result -= (ref * ((mask & this->_nbr) > 0));
		else
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

// Static Memeber functions
Fixed& Fixed::min( Fixed & lhs, Fixed& rhs )
{
	if (rhs < lhs)
		return (rhs);
	return (lhs);
}

const Fixed& Fixed::min( const Fixed & lhs, const Fixed& rhs )
{
	if (&rhs < &lhs)
		return (rhs);
	return (lhs);
}

Fixed& Fixed::max( Fixed & lhs, Fixed& rhs )
{
	if (rhs < lhs)
		return (lhs);
	return (lhs);
}

const Fixed& Fixed::max( const Fixed & lhs, const Fixed& rhs )
{
	if (&rhs < &lhs)
		return (lhs);
	return (lhs);
}
