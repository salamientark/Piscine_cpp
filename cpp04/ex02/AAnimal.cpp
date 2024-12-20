/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:37 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 09:20:33 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
AAnimal::AAnimal( void ) : type("animal")
{
	std::cout << "Called default AAnimal Constructor" << std::endl;
	return ;
}

AAnimal::AAnimal( AAnimal const & rhs )
{
	*this = rhs;
	std::cout << "Called copy AAnimal Constructor" << std::endl;
	return ;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Called default AAnimal Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string	AAnimal::getType( void ) const
{
	return (this->type);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
AAnimal& AAnimal::operator=( AAnimal const & rhs )
{
	if (this != &rhs) {
		std::cout << "Called AAnimal assignment operator" << std::endl;
		this->type = rhs.getType();
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */

void	AAnimal::makeSound( void ) const
{
	std::cout << "JuJuJuL" << std::endl;
	return ;
}
