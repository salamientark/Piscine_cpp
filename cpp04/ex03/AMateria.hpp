/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:42:01 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 17:31:59 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "Character.hpp"

class AMateria
{
	protected:
		std::string	type;
		// [...]

	public:
		AMateria( void );					// Cannonical
		AMateria(std::string const & type);
		AMateria( AMateria const & rhs );	// Cannoical
		virtual ~AMateria( void );			// Caninical

		AMateria& operator=( AMateria const & rhs );
		// [...]

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};

#endif // !AMATERIA_HPP
