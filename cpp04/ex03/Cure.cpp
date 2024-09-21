/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:33:34 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 16:02:06 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Cure::Cure( void ) : AMateria()
{
	this->type = "cure";
	std::cout << "Called default Cure Constructor" << std::endl;
	return ;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	return ;
}

Cure::Cure( Cure const & rhs ) : AMateria(rhs)
{
	*this = rhs;
	std::cout << "Called copy Cure Constructor" << std::endl;
	return ;
}

Cure::~Cure( void )
{
	std::cout << "Called default Cure Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Cure& Cure::operator=( Cure const & rhs )
{
	std::cout << "Called Cure assignment operator" << std::endl;
	this->type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
AMateria*	Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
