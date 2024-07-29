/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:42:30 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 21:11:15 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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
	

	return (0);
}
