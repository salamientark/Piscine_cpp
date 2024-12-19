/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:15:31 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 22:42:50 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

# define SCAVTRAP_EP 50

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const & rhs );
	virtual ~DiamondTrap();

	DiamondTrap& operator=( DiamondTrap const & rhs );

	void	attack( const std::string& target );
	void	whoAmI( void ) const;

private:
	std::string	_name;
	
};

#endif // !DIAMONDTRAP_HPP
