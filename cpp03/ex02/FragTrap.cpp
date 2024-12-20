/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:02:41 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 21:07:53 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap " << this->_name
		<< " was created using default FragTrap Constructor" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_damage = 30;
	
	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name
		<< " was created using parametric FragTrap Constructor" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_damage = 30;
	
	return ;
}

FragTrap::FragTrap( FragTrap const & rhs ) : ClapTrap(rhs)
{
	*this = rhs;
	std::cout << "FragTrap " << this->_name
		<< " was Created using copy FragTrap Constructor" << std::endl;

	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
FragTrap&	FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHP();
		this->_ep = rhs.getEP();
		this->_damage = rhs.getDamage();	
	}

	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name
		<< " would be happy to make a highfive" << std::endl;
	return ;
}
