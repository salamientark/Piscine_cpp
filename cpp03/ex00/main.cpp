/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:42:30 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 19:51:57 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int	main( void )
{
	ClapTrap	john("John");
	ClapTrap	mickael("mickael");

	for(int i = 0; i < 10; i++)
	{
		mickael.attack(john.getName());
		john.takeDamage(mickael.getDamage());
	}
	mickael.attack(john.getName());
	mickael.beRepaired(100);
	john.beRepaired(100);
	mickael.takeDamage(100);
	john.takeDamage(100);
	john.takeDamage(100);
	john.beRepaired(1000);

	return (0);
}
