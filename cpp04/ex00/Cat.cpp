/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:45:45 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 14:59:49 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Cat::Cat( void ) : Animal()
{
	this->type = "cat";
	std::cout << "Called default Cat Constructor" << std::endl;
	return ;
}


Cat::Cat( Cat const & rhs ) : Animal( rhs )
{
	*this = rhs;
	std::cout << "Called copy Cat Constructor" << std::endl;
	return ;
}

Cat::~Cat( void )
{
	std::cout << "Called default Cat Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Cat& Cat::operator=( Cat const & rhs )
{
	this->type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	Cat::makeSound( void ) const
{
	std::cout << "Miaou" << std::endl;
}
