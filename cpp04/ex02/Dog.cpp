/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:53:11 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 18:57:41 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Dog::Dog( void ) : AAnimal(), _brain(new Brain())
{
	this->type = "dog";
	std::cout << "Called default Dog Constructor" << std::endl;
	return ;
}


Dog::Dog( Dog const & rhs ) : AAnimal( rhs ), _brain(new Brain())
{
	*this = rhs;
	std::cout << "Called copy Dog Constructor" << std::endl;
	return ;
}

Dog::~Dog( void )
{
	delete(this->_brain);
	std::cout << "Called default Dog Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Dog& Dog::operator=( Dog const & rhs )
{
	std::cout << "Called Dog assignment operator" << std::endl;
	this->type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	Dog::makeSound( void ) const
{
	std::cout << "Wouf" << std::endl;
}
