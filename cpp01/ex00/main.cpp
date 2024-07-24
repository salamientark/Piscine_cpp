/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:51 by madlab            #+#    #+#             */
/*   Updated: 2024/07/24 06:45:01 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie*	zombie_a = newZombie("Jojo");

	randomChump("Bob");
	zombie_a->annonce();
	delete zombie_a;
}
