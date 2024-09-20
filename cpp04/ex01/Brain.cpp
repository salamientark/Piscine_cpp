/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:04:13 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 18:36:56 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Brain::Brain( void )
{
	std::cout << "Called default Brain Constructor" << std::endl;
	return ;
}

Brain::Brain( Brain const & rhs )
{
	*this = rhs;
	std::cout << "Called copy Brain Constructor" << std::endl;
	return ;
}

Brain::~Brain( void )
{
	std::cout << "Called default Brain Destructor" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
const std::string*	Brain::getIdeas( void ) const
{
	return (this->ideas);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Brain&	Brain::operator=( Brain const & rhs)
{
	std::cout << "Called Brain assignment operator" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.getIdeas()[i];
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */

