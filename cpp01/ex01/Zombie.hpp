/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:35:56 by madlab            #+#    #+#             */
/*   Updated: 2024/07/16 21:59:02 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
public:
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );

	void		setName( std::string name );

	void		annonce( void );
private:
	std::string	name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif
