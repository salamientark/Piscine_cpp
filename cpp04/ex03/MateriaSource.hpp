/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:22:10 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 15:51:21 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HP
# define MATERIASOURCE_HP

#include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource( void );
	MateriaSource( MateriaSource const & rhs );
	~MateriaSource();

	AMateria*	getMateriaIndex( int idx ) const;
	int			getLastMaterial( void ) const;

	MateriaSource& operator=( MateriaSource const & rhs );

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

private:
	AMateria*	_materia[4];
	int			_last_materia;
	
};

#endif // !MATERIASOURCE_HP
