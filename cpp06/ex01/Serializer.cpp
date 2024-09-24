/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:30:47 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 12:47:45 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Serializer::Serializer( void )
{
	return ;
}

Serializer::Serializer( Serializer const & rhs )
{
	(void) rhs;
	return ;
}

Serializer::~Serializer( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Serializer& Serializer::operator=( Serializer const & rhs )
{
	(void) rhs;
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
uintptr_t	Serializer::serialize( Data* ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data*>(raw));
}
