/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 08:34:17 by madlab            #+#    #+#             */
/*   Updated: 2024/07/29 10:23:02 by dbaladro         ###   ########.fr       */
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
	if ((nbr & 0x80000000) == 0)
		this->_nbr = ((nbr << 8) & 0x7FFFFFFF);
	else
		this->_nbr = ((nbr << 8) | 0x8000000);
	return ;
}

Fixed::Fixed( const float nbr )
{
	if (nbr < 0)
		this->_nbr = roundf(nbr * (1 << Fixed::_fractBitNbr));
	else
		this->_nbr = (((int)roundf(-nbr * (1 << Fixed::_fractBitNbr))) ^ 0xFFFFFFFF) + 1;	 

	return ;
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
	Fixed	result;
	result.setRawBits(this->_nbr + rhs.getRawBits());

	return (result);
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	Fixed	result;
	result.setRawBits(this->_nbr - rhs.getRawBits());

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
	char	sign = (this->_nbr & 0x80000000) != 0;
	int		abs_nbr = ((this->_nbr & 0x80000000) != 0 ? (this->_nbr ^ 0xFFFFFFFF) + 1 : this->_nbr);
	float	result = (float)(abs_nbr >> 8);
	int		mask = 128;
	float	ref = 0.5f;

	for (int i = 0; i < 8; i++)	
	{
		result += (ref * ((mask & abs_nbr) > 0));
		ref /= 2;
		mask = (mask >> 1);
	}
	if (sign == 0)
		return (result);
	return (-result);
}

int		Fixed::toInt( void ) const
{
	if ((this->_nbr & 0x80000000) == 0)
		return ((this->_nbr >> 8));
	return ((this->_nbr >> 8) | 0xFF000000);
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
	return (rhs);
}

const Fixed& Fixed::max( const Fixed & lhs, const Fixed& rhs )
{
	if (&rhs < &lhs)
		return (lhs);
	return (rhs);
}
