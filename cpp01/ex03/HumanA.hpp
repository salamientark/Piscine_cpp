/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:46:47 by madlab            #+#    #+#             */
/*   Updated: 2024/07/17 10:13:38 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {
public:
	HumanA( std::string name, Weapon& weapon );
	~HumanA( void );

	void	attack( void ) const;

private:
	std::string	name;
	Weapon&		weapon;
};

#endif // HUMANA_HPP
