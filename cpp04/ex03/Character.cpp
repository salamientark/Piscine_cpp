/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:58:57 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 18:35:39 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

AMateria* Character::floor[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL};

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Character::Character( void ) : _name("")
{
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

Character::Character( std::string name ) : _name(name)
{
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

Character::Character( Character const & rhs ) : _name(rhs.getName())
{
	// *this = rhs;
	for (int i = 0; i < 3; i++)
		this->_inventory[i] = rhs.getInventoryIdx(i)->clone();
	return ;
}

Character::~Character( void )
{
	for (int i = 0; i < 3; i++) {
		if (this->_inventory[i])
			delete(this->_inventory[i]);
	}
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
AMateria* Character::getInventoryIdx( int idx ) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_inventory[idx]);
}

std::string	const &	Character::getName() const
{
	return (this->_name);
}
/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Character& Character::operator=( Character const & rhs )
{
	std::cout << "Called Character assignment operator" << std::endl;
	this->_name = rhs.getName();
	for (int i = 0; i < 3; i++) {
		if (this->_inventory[i])
			delete(this->_inventory[i]);
		this->_inventory[i] = rhs.getInventoryIdx(i)->clone();
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "* equip() : Nothing to equip *" << std::endl;
		return ;
	}
	for(int i = 0; i < 3; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "* equip() : Inventory is full *" << std::endl;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "* unequip() : Index out of bound *" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout <<  "* unequip() : Nothing at index " << idx << " *"
			<< std::endl;
		return ;
	}
	int	i = 0;
	while (i < 10 && Character::floor[i])
		i++;
	i %= 10;
	Character::floor[i] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "* use() : Index out of bound *" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "* use() : Nothing to use *" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
	return ;
}
