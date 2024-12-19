/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:35:50 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 20:58:22 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "Claptrap.hpp"
#include <iostream>
#include <string>

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
ScavTrap::ScavTrap( void ) : ClapTrap() 
{
	std::cout << "ScavTrap " << this->_name
		<< " was created using default  ScavTrap Constructor" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_damage = 20;
	
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name
		<< " was created using parametric ScavTrap Constructor" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_damage = 20;
	
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & rhs ) : ClapTrap(rhs)
{
	*this = rhs;
	std::cout << "ScavTrap " << this->_name << " was Created using copy Scavtrap Constructor" << std::endl;

	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
ScavTrap&	ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "Scavtrap assignment operator called" << std::endl;
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
void	ScavTrap::attack(const std::string& target)
{
	if (this->_hp <= 0){
		std::cout << "ScavTrap " << this->_name
				<< " tried to fireball stuff but he is dead!" << std::endl;
		return ;
	}
	if (this->_ep <= 0){
		std::cout << "ScavTrap " << this->_name
				<< " tried to attack but he is to tired" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " use fireball on " << target
		<< ", causing " << this->_damage << " points of fire damage!" << std::endl;
	this->_ep--;
	return ;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name
		<< " is now in Gate Keeper mode!" << std::endl;
	return ;
}
