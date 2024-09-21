/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:23:51 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 17:36:52 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
MateriaSource::MateriaSource( void ) : _last_materia(0)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	return ;
}

MateriaSource::MateriaSource( MateriaSource const & rhs )
{
	// *this = rhs;
	for (int i = 0; i < 4; i++){
		this->_materia[i] = rhs.getMateriaIndex(i);
	}
	this->_last_materia = rhs.getLastMaterial();
	return ;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++){
		if (this->_materia[i])
			delete(this->_materia[i]);
	}
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
AMateria*	MateriaSource::getMateriaIndex( int idx ) const
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "getMateriaIndex() : Index out of bound" << std::endl;
		return (NULL);
	}
	return (this->_materia[idx]);
}

int	MateriaSource::getLastMaterial( void ) const
{
	return (this->_last_materia);
}
/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
MateriaSource& MateriaSource::operator=( MateriaSource const & rhs )
{
	for (int i = 0; i < 3; i++) {
		if (this->_materia[i])
			delete(this->_materia[i]);
		this->_materia[i] = rhs.getMateriaIndex(i)->clone();
	}
	this->_last_materia = rhs.getLastMaterial();
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m) {
		std::cout << "* learnMateria() : Nothing to learn *" << std::endl;
		return ;
	}
	this->_materia[this->_last_materia] = m;
	this->_last_materia = (this->_last_materia + 1) % 4;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++){
		if (this->_materia[i] && this->_materia[i]->getType().compare(type) == 0)
			return (this->_materia[i]->clone());
	}
	std::cout << "* createMateria() : couldn't find " << type << " *"
		<< std::endl;
	return (NULL);
}
