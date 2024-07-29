/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:56:56 by madlab            #+#    #+#             */
/*   Updated: 2024/07/29 08:04:10 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
public:
	Point( void );
	Point( Point const & rhs );
	Point( const Fixed x, const Fixed y );
	~Point();

	Point& operator=( Point const & rhs );

	Fixed	getXCoord( void ) const;
	Fixed	getYCoord( void ) const;

private:
	Fixed	_x;
	Fixed	_y;
};

bool	is_point_inside_triangle(const Point p, const Point a, const Point b, const Point c);

#endif // !POINT_HPP
