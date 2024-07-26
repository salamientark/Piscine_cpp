/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:02:24 by madlab            #+#    #+#             */
/*   Updated: 2024/07/24 06:42:28 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde( int N, std::string name )
{
	if (N < 0) {
		std::cerr << "Negative horde count, serously ?!" << std::endl;
		return (NULL);
	}
	if (N == 0) {
		std::cerr << "No horde count, serously ?!" << std::endl;
		return (NULL);
	}
	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}
