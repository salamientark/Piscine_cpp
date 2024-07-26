/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:37:52 by madlab            #+#    #+#             */
/*   Updated: 2024/07/22 19:57:38 by madlab           ###   ########.fr       */
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
	// Implement <, >, <=, >=, ==, !=
	bool	operator<( const Fixed & rhs);
	bool	operator>( const Fixed & rhs);
	bool	operator<=( const Fixed & rhs);
	bool	operator>=( const Fixed & rhs);
	bool	operator==( const Fixed & rhs);
	bool	operator!=( const Fixed & rhs);
	
	// Implement +, -, *, /
	Fixed&	operator+( const Fixed & rhs);
	Fixed&	operator-( const Fixed & rhs);
	Fixed&	operator*( const Fixed & rhs);
	Fixed&	operator/( const Fixed & rhs);

	// Implement ++X, X++, --X, X--
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	// Implemnt
	static Fixed &	min(Fixed & lnb, Fixed & rnb);
	static const Fixed &	min(const Fixed & lnb, const Fixed & rnb);
	static Fixed &	max(Fixed & lnb, Fixed & rnb);
	static const Fixed &	max(const Fixed & lnb, const Fixed & rnb);
	static Fixed powTwo( int pow );

	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	static const int	_fractBitNbr = 8;

	int		_nbr;
};

std::ostream & 	operator<<( std::ostream & o, const Fixed & rhs );

#endif // !FIXED_HPP
