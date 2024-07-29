/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:00:16 by dbaladro          #+#    #+#             */
/*   Updated: 2024/07/29 22:18:02 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "Claptrap.hpp"
#include <string>

class FragTrap : public virtual ClapTrap {
public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( FragTrap const & rhs );
	~FragTrap();

	FragTrap& operator=( FragTrap const & rhs );

	void	highFivesGuys( void );

private:
	
};

#endif // !FRAGTRAP_HPP
