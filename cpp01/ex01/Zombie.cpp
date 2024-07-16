/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:40:08 by madlab            #+#    #+#             */
/*   Updated: 2024/07/16 21:58:56 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

// ************************************************************************** //
//                               Constructor & Destructor                     //
// ************************************************************************** //

Zombie::Zombie( void ) : name("default")
{
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << this->name << " was created !" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << this->name << " was destroyed !" << std::endl;
}


// ************************************************************************** //
//                           Public Member function                           //
// ************************************************************************** //

void	Zombie::annonce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// ************************************************************************** //
//                              Getter & Setter                               //
// ************************************************************************** //
void	Zombie::setName( std::string name )
{
	this->name = name;
}
