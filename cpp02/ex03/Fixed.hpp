/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 07:21:24 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 07:21:27 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed {
public:
	Fixed( void );
	Fixed( const int nbr );
	Fixed( const float nbr );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed &	operator=( Fixed const & rhs );
	
	// Implement operator <, >, <=, >=, ==, !=
	bool	operator<( Fixed const & rhs) const; 
	bool	operator>( Fixed const & rhs) const; 
	bool	operator<=( Fixed const & rhs) const; 
	bool	operator>=( Fixed const & rhs) const; 
	bool	operator==( Fixed const & rhs) const; 
	bool	operator!=( Fixed const & rhs) const; 
	
	// Implement +, -, *, /
	Fixed	operator+( Fixed const & rhs) const;
	Fixed	operator-( Fixed const & rhs) const;
	Fixed	operator*( Fixed const & rhs) const;
	Fixed	operator/( Fixed const & rhs) const;
	
	// Implement ++X, X++, --X, X--
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed&	min( Fixed& lhs, Fixed& rhs );
	static const Fixed&	min( const Fixed& lhs, const Fixed& rhs );
	static Fixed&	max( Fixed& lhs, Fixed& rhs );
	static const Fixed&	max( const Fixed& lhs, const Fixed& rhs );

private:
	static const int	_fractBitNbr = 8;

	int		_nbr;
};

std::ostream & 	operator<<( std::ostream & o, const Fixed & rhs );

#endif // !FIXED_HPP
