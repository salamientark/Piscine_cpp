/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:42:30 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 20:57:39 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	john("john");
	ScavTrap	flavier("flavier");

	flavier.guardGate();
	flavier.attack(john.getName());
	john.takeDamage(flavier.getDamage());
	flavier.attack(flavier.getName());
	flavier.takeDamage(flavier.getDamage());
	flavier.attack(flavier.getName());
	flavier.takeDamage(flavier.getDamage());
	flavier.attack(flavier.getName());
	flavier.takeDamage(flavier.getDamage());
	flavier.attack(flavier.getName());
	flavier.takeDamage(flavier.getDamage());
	flavier.attack(flavier.getName());
	flavier.takeDamage(flavier.getDamage());
	flavier.attack(flavier.getName());
	flavier.takeDamage(flavier.getDamage());

	return (0);
}
