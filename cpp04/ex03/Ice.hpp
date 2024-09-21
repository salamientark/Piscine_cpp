/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:20:26 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 20:22:44 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice( void );
	Ice( std::string const & type );
	Ice( Ice const & rhs );
	~Ice();

	Ice& operator=( Ice const & rhs );

private:
	AMateria* clone() const;
	void use(ICharacter& target);
	
};

#endif // !ICE_HPP
