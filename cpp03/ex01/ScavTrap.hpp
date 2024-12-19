/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:54:18 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 20:33:47 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "Claptrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & rhs );
	virtual ~ScavTrap();

	ScavTrap& operator=( ScavTrap const & rhs );

	void	attack( const std::string& target );
	void	guardGate( void );

private:
};

#endif // !SCAVTRAP_HPP
