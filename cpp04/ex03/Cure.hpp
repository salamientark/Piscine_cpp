/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:34:03 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 20:36:46 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure( void );
		Cure( Cure const & rhs );
		Cure(std::string const & type);
		~Cure();

		Cure& operator=( Cure const & rhs );

		AMateria*	clone() const;
		void	use(ICharacter& target);

	private:
	
};

#endif // !CURE_HPP
