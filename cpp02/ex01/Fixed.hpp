/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:37:52 by madlab            #+#    #+#             */
/*   Updated: 2024/07/22 09:57:04 by madlab           ###   ########.fr       */
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

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	static const int	_fractBitNbr = 8;

	int		_nbr;
};

std::ostream & 	operator<<( std::ostream & o, const Fixed & rhs );

#endif // !FIXED_HPP
