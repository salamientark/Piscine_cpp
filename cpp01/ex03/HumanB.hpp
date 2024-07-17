/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:46:47 by madlab            #+#    #+#             */
/*   Updated: 2024/07/17 10:07:30 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {
public:
	HumanB( std::string name );
	~HumanB( void );

	void	setWeapon( Weapon weapon );

	void	attack( void ) const;

private:
	std::string	name;
	Weapon*		weapon;
};

#endif // HUMANA_HPP
