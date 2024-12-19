/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:20:34 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 22:55:40 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "Claptrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
DiamondTrap::DiamondTrap( void ) : ClapTrap("_clap_name"), _name()
{
	std::cout << "DiamondTrap " << this->ClapTrap::_name
		<< " was created using default DiamondTrap Constructor" << std::endl;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_damage = FragTrap::_damage;
	
	return ;
}

DiamondTrap::DiamondTrap( std::string name )
	: ClapTrap(name + "_clap_name"), _name(name)
{
	std::cout << "DiamondTrap " << this->ClapTrap::_name
		<< " was created using parametric DiamondTrap Constructor" << std::endl;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_damage = FragTrap::_damage;
	
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & rhs )
	: ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	*this = rhs;
	std::cout << "DiamondTrap " << this->_name
		<< " was Created using copy DiamondTrap Constructor" << std::endl;

	return ;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
DiamondTrap&	DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
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
void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void ) const
{
	std::cout << "My ClapTrap name is " << this->ClapTrap::_name
		<< ". My DiamondTrap name is " << this->_name << std::endl;
}
