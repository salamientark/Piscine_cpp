/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:35:56 by madlab            #+#    #+#             */
/*   Updated: 2024/07/16 22:47:13 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {
public:
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );

	void	annonce( void );
private:
	std::string	name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
