/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 08:34:17 by madlab            #+#    #+#             */
/*   Updated: 2024/07/26 08:40:54 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
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

Fixed::Fixed( const float nbr )
{
	this->_nbr = (round(nbr * (1 << Fixed::_fractBitNbr)));
	if (nbr < 0 && (this->_nbr & 0xFF) != 0)
		this->_nbr += 256;
}

Fixed::Fixed( Fixed const & rhs )
{
	*this = rhs;
}

Fixed::~Fixed( void )
{
}
// Constructor and Destructor END

// OPERATOR OVERLOAD
Fixed & Fixed::operator=( Fixed const & rhs )
{
	this->_nbr = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator<( const Fixed & rhs ) const
{
	return (this->_nbr < rhs.getRawBits());
}

bool	Fixed::operator>( const Fixed & rhs ) const
{
	return (this->_nbr > rhs.getRawBits());
}

bool	Fixed::operator<=( const Fixed & rhs ) const
{
	return (!(this->_nbr > rhs.getRawBits()));
}

bool	Fixed::operator>=( const Fixed & rhs ) const
{
	return (!(this->_nbr < rhs.getRawBits()));
}

bool	Fixed::operator==( const Fixed & rhs ) const
{
	return (this->_nbr == rhs.getRawBits());
}

bool	Fixed::operator!=( const Fixed & rhs ) const
{
	return (this->_nbr != rhs.getRawBits());
}

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	return (Fixed(this->_nbr + rhs.getRawBits()));
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	Fixed	result;
	result.setRawBits(this->_nbr - rhs.getRawBits());
	if (rhs.toFloat() > this->toFloat())
		result.setRawBits(result.getRawBits() + 256);
	return (result);
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	Fixed	result;
	result.setRawBits((this->_nbr * rhs.getRawBits()) >> 8);

	return (result);
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	Fixed	result;
	result.setRawBits((this->_nbr << 8) / rhs.getRawBits());

	return (result);
}

Fixed&	Fixed::operator++( void )
{
	this->_nbr++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	old = *this;
	this->_nbr++;
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
