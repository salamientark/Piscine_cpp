/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:11:14 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 15:14:04 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal {
public:
	WrongCat( void );
	WrongCat( WrongCat const & rhs );
	~WrongCat();

	WrongCat& operator=( WrongCat const & rhs );

	void	makeSound( void ) const;

private:
	
};

#endif // !WRONGCAT_HPP
