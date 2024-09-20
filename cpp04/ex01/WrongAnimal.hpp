/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:14:12 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 15:26:10 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
class WrongAnimal {
	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const & rhs );
		virtual ~WrongAnimal();

		WrongAnimal& operator=( WrongAnimal const & rhs );

		std::string	getType( void ) const;

		void	makeSound( void ) const;

	protected:
		std::string	type;

	private:
	
};

#endif // !WRONGANIMAL_HPP
