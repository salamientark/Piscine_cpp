/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 07:21:39 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 12:28:21 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
 * Indicate if the point pt is inside the triangle made by a, b, c
 * using cross product in an optimised maner
 * We consider that a point is inside a Triangle if it is note on the border
 * */
bool	is_point_inside_triangle(const Point p, const Point a, const Point b, const Point c)
{
	Fixed	vec_pa_x = p.getXCoord() - a.getXCoord();
	Fixed	vec_pa_y = p.getYCoord() - a.getYCoord();

	bool	pab = ((b.getXCoord() - a.getXCoord()) * vec_pa_y) - ((b.getYCoord() - a.getYCoord()) * vec_pa_x) > Fixed(0);

	if (((((c.getXCoord() - a.getXCoord()) * vec_pa_y) - ((c.getYCoord() - a.getYCoord()) * vec_pa_x)) > Fixed(0)) == pab)
		return (false);
	if (((((c.getXCoord() - b.getXCoord()) * (p.getYCoord() - b.getYCoord())) - ((c.getYCoord() - b.getYCoord()) * (p.getXCoord() - b.getXCoord()))) > Fixed(0)) != pab)
		return (false);
	return (true);
}
