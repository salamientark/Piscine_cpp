/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:00:16 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 21:05:53 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "Claptrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( FragTrap const & rhs );
	virtual ~FragTrap();

	FragTrap& operator=( FragTrap const & rhs );

	void	highFivesGuys( void );

private:
	
};

#endif // !FRAGTRAP_HPP
