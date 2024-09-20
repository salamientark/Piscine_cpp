/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:29:25 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 14:59:23 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
class Cat : public Animal {
public:
	Cat( void );
	Cat( Cat const & rhs );
	~Cat();

	Cat& operator=( Cat const & rhs );

	void	makeSound( void ) const;

private:
	
};

#endif // !CAT_HPP
