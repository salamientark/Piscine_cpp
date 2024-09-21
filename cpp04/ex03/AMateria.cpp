/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:37 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 15:58:41 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
AMateria::AMateria( void ) : type("")
{
	std::cout << "Called default AMateria Constructor" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	return ;
}

AMateria::AMateria( AMateria const & rhs )
{
	*this = rhs;
	std::cout << "Called copy AMateria Constructor" << std::endl;
	return ;
}

AMateria::~AMateria( void )
{
	std::cout << "Called default AMateria Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string	const & AMateria::getType( void ) const
{
	return (this->type);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
AMateria& AMateria::operator=( AMateria const & rhs )
{
	std::cout << "Called AMateria assignment operator" << std::endl;
	this->type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */

