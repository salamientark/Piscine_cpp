/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:42:01 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 18:09:23 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
	public:
		Animal( void );
		Animal( Animal const & rhs );
		virtual ~Animal();

		Animal& operator=( Animal const & rhs );

		std::string	getType( void ) const;

		virtual void	makeSound( void ) const;

	protected:
		std::string	type;

	private:
	
};

#endif // !ANIMAL_HPP
