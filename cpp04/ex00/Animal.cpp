/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:37 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 18:39:33 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Animal::Animal( void ) : type("animal")
{
	std::cout << "Called default Animal Constructor" << std::endl;
	return ;
}

Animal::Animal( Animal const & rhs )
{
	*this = rhs;
	std::cout << "Called copy Animal Constructor" << std::endl;
	return ;
}

Animal::~Animal( void )
{
	std::cout << "Called default Animal Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string	Animal::getType( void ) const
{
	return (this->type);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Animal& Animal::operator=( Animal const & rhs )
{
	std::cout << "Called Animal assignment operator" << std::endl;
	this->type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */

void	Animal::makeSound( void ) const
{
	std::cout << "JuJuJuL" << std::endl;
	return ;
}
