/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:20:46 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 19:43:51 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
class ClapTrap {
public:
	ClapTrap( void ); // Canonical
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const & rhs ); // Canonical
	~ClapTrap(); // Canonical

	ClapTrap& operator=( ClapTrap const & rhs ); // Canonical

	std::string	getName( void ) const;
	int			getHP( void ) const;
	int			getEP( void ) const;
	int			getDamage( void ) const;

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned	int amount);

private:
	std::string	_name;
	int			_hp;
	int			_ep;
	int			_damage;
};

#endif // !CLAPTRAP_HPP
