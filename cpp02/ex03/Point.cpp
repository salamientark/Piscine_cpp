/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:59:34 by madlab            #+#    #+#             */
/*   Updated: 2024/07/29 12:12:51 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/* ************************************************************************** */
/* ************************ Constructor and destructor ********************** */
/* ************************************************************************** */
// Default Constructor
Point::Point( void ) : _x(Fixed()), _y(Fixed())
{

}

// Copy constructor
Point::Point( Point const & rhs )
{
	*this = rhs;
}

// Usefull Constructor
Point::Point( const Fixed x, const Fixed y ) : _x(x), _y(y)
{

}

Point::~Point( void )
{

}

/* ************************************************************************** */
/* ***************************** Operator Overload*************************** */
/* ************************************************************************** */
Point&	Point::operator=( Point const & rhs )
{
	this->_x = rhs.getXCoord();
	this->_y = rhs.getYCoord();

	return (*this);
}

/* ************************************************************************** */
/* ***************************** Getter and Setters ************************* */
/* ************************************************************************** */
Fixed	Point::getXCoord( void ) const
{
	return (this->_x);
}

Fixed	Point::getYCoord( void ) const
{
	return (this->_y);
}

/* ************************************************************************** */
/* ************************* Public Member Function ************************* */
/* ************************************************************************** */
