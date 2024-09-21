/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:22:56 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 16:02:31 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Ice::Ice( void ) : AMateria()
{
	this->type = "ice";
	std::cout << "Called default Ice Constructor" << std::endl;
	return ;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
	return ;
}

Ice::Ice( Ice const & rhs ) : AMateria(rhs)
{
	*this = rhs;
	std::cout << "Called copy Ice Constructor" << std::endl;
	return ;
}

Ice::~Ice( void )
{
	std::cout << "Called default Ice Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Ice& Ice::operator=( Ice const & rhs )
{
	std::cout << "Called Ice assignment operator" << std::endl;
	this->type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
AMateria*	Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
}
