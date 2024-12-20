/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:16:44 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 09:10:31 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
WrongAnimal::WrongAnimal( void ) : type("wrongAnimal")
{
	std::cout << "Called default WrongAnimal Constructor" << std::endl;
	return ;
}


WrongAnimal::WrongAnimal( WrongAnimal const & rhs )
{
	*this = rhs;
	std::cout << "Called copy WrongAnimal Constructor" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Called default WrongAnimal Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
WrongAnimal& WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if (this != &rhs) {
		std::cout << "Called WrongAnimal assignment operator" << std::endl;
		this->type = rhs.getType();
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Badabapbang!" << std::endl;
}
