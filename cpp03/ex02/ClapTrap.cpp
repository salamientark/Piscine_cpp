/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:25:06 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 19:51:12 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include <iostream>
#include <string>

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
ClapTrap::ClapTrap( void ) : _name(""), _hp(10), _ep(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " was created using default Constructor" << std::endl;
	
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _ep(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " was created using parametric Constructor" << std::endl;
	
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & rhs )
{
	*this = rhs;
	std::cout << "ClapTrap " << this->_name << " was Created using copy Constructor" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Claptrap Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

int			ClapTrap::getHP( void ) const
{
	return (this->_hp);
}

int			ClapTrap::getEP( void ) const
{
	return (this->_ep);
}

int			ClapTrap::getDamage( void ) const
{
	return (this->_damage);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
ClapTrap&	ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "Claptrap assignment operator called" << std::endl;
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
void	ClapTrap::attack(const std::string& target)
{
	if (this->_hp <= 0){
		std::cout << "Claptrap " << this->_name
				<< " tried to attack but has no hp left..." << std::endl;
		return ;
	}
	if (this->_ep <= 0){
		std::cout << "Claptrap " << this->_name
				<< " tried to attack but has no more energy" << std::endl;
		return ;
	}
	std::cout << "Claptrap " << this->_name << " attacks " << target
		<< ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_ep--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0){
		std::cout << "Claptrap " << this->_name
			<< " is already dead.\nYou Psycho !" << std::endl;
		return ;
	}
	if (amount == 0){
		std::cout << "Claptrap " << this->_name
			<< " took 0 damage, he nearly died" << std::endl;
		return ;
	}
	if (amount >= (unsigned int)this->_hp){
		this->_hp = 0;
		std::cout << "Claptrap " << this->_name
			<< " took " << amount << " damage. He died. RIP" << std::endl;
		return ;
	}
	this->_hp -= amount;
	std::cout << "Claptrap " << this->_name << " took " << amount
		<< " damage. He survived with " << this->_hp << "HP" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0){
		std::cout << "Claptrap " << this->_name
			<< " is dead, he cannot resurect !" << std::endl;
		return ;
	}
	if (this->_ep <= 0){
		std::cout << "Claptrap " << this->_name
			<< " tried to repair but has no more energy !" << std::endl;
		return ;
	}
	this->_hp += amount;
	this->_ep--;
	std::cout << "Claptrap " << this->_name
		<< " repaired himself, he gained " << amount << "HP." << std::endl;
	return ;
}
