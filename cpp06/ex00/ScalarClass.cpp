/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:37 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 11:34:22 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarClass.hpp"

const char*	ScalarClass::InvalidParameterException::what( void ) const throw()
{
	return ("Parameter is neither a char or int or float or double");
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
ScalarClass::ScalarClass( void )
{
	return ;
}

ScalarClass::ScalarClass( ScalarClass const & rhs )
{
	(void) rhs;
	return ;
}

ScalarClass::~ScalarClass( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
ScalarClass& ScalarClass::operator=( ScalarClass const & rhs )
{
	(void) rhs;
	return (*this);
}


/* ************************************************************************** */
/*                             Public Member Function                         */
