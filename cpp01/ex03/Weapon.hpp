/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:29:45 by madlab            #+#    #+#             */
/*   Updated: 2024/07/16 23:43:07 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
public:
	Weapon( void );
	Weapon( std::string type );
	~Weapon( void );

	const std::string&	getType( void ) const;
	void				setType( std::string type );

private:
	std::string	type;
};

#endif
