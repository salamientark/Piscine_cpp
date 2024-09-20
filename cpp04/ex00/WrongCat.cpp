/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:19:24 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 15:24:56 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
WrongCat::WrongCat( void ) : WrongAnimal()
{
	this->type = "wrongCat";
	std::cout << "Called default WrongCat Constructor" << std::endl;
	return ;
}


WrongCat::WrongCat( WrongCat const & rhs ) : WrongAnimal()
{
	*this = rhs;
	std::cout << "Called copy WrongCat Constructor" << std::endl;
	return ;
}

WrongCat::~WrongCat( void )
{
	std::cout << "Called default WrongCat Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
WrongCat& WrongCat::operator=( WrongCat const & rhs )
{
	this->type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	WrongCat::makeSound( void ) const
{
	std::cout << "Zapzap!" << std::endl;
}
