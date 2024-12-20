/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:42:30 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 22:47:48 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main( void )
{
	ClapTrap	john("john");
	ScavTrap	flavier("flavier");
	FragTrap	xavien("xavien");

	xavien.highFivesGuys();
	xavien.beRepaired(0);
	xavien.attack(flavier.getName());
	flavier.takeDamage(xavien.getDamage());
	flavier.attack(xavien.getName());
	xavien.takeDamage(flavier.getDamage());
	xavien.attack(john.getName());
	john.takeDamage(xavien.getDamage());
	
	std::cout << std::endl;

	DiamondTrap	olivian("olivian");
	std::cout << "Olivian has " << olivian.getEP() << " Energy point." << std::endl;
	olivian.highFivesGuys();
	olivian.guardGate();
	olivian.whoAmI();
	olivian.attack(john.getName());
	john.takeDamage(olivian.getDamage());
	olivian.attack(olivian.getName());
	olivian.takeDamage(olivian.getDamage());

	return (0);
}
