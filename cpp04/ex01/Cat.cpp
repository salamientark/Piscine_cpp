/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:45:45 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/19 23:25:03 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Cat::Cat( void ) : Animal(), _brain(new Brain())
{
	this->type = "cat";
	std::cout << "Called default Cat Constructor" << std::endl;
	return ;
}


Cat::Cat( Cat const & rhs ) : Animal( rhs ), _brain(new Brain(*rhs._brain))
{
	std::cout << "Called copy Cat Constructor" << std::endl;
	return ;
}

Cat::~Cat( void )
{
	if (this->_brain)
		delete(this->_brain);
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
	if (this != &rhs) {
		std::cout << "Called Cat assignment operator" << std::endl;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
		this->type = rhs.getType();
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	Cat::makeSound( void ) const
{
	std::cout << "Miaou" << std::endl;
}
