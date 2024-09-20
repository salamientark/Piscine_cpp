/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:34:24 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 18:10:20 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
class Dog : public Animal {
	public:
		Dog( void );
		Dog( Dog const & rhs );
		~Dog();

		Dog& operator=( Dog const & rhs );

		void	makeSound( void ) const;

	private:
		Brain*	_brain;
	
};

#endif // !DOG_HPP
