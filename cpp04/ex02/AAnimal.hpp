/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:42:01 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 18:53:40 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal {
	public:
		AAnimal( void );
		AAnimal( AAnimal const & rhs );
		virtual ~AAnimal();

		AAnimal& operator=( AAnimal const & rhs );

		std::string	getType( void ) const;

		virtual void	makeSound( void ) const = 0;

	protected:
		std::string	type;

	private:
	
};

#endif // !AANIMAL_HPP
