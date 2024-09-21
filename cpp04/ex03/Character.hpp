/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:52:42 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 18:35:18 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

// #include "AMateria.hpp"
# include "ICharacter.hpp"
#include <string>


class Character : public ICharacter {
public:
	Character( void );
	Character( std::string name );
	Character( Character const & rhs );
	~Character();

	Character& operator=( Character const & rhs );

	AMateria* getInventoryIdx( int idx ) const;

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	static AMateria*	floor[10];

private:
	std::string	_name;
	AMateria* _inventory[4];
	
};

#endif // !CHARACTER_HPP
