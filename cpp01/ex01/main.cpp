/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:51 by madlab            #+#    #+#             */
/*   Updated: 2024/07/24 06:46:48 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie*	horde = zombieHorde(5, "Jojo");
	if (!horde)
		return (0);
	
	horde[0].annonce();
	horde[1].annonce();
	horde[2].annonce();
	horde[3].annonce();
	horde[4].annonce();
	delete [] horde;
	return (0);
}
