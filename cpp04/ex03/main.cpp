/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:41:57 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/21 18:40:03 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// Own test
	ICharacter*	glgl = new Character("glgl");
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Test with innvalid material
	tmp = src->createMateria("fire");
	glgl->equip(tmp);					// Try to equip it
	tmp = src->createMateria("ice");	// Create new Ice material
	glgl->equip(tmp);


	// Test unequip invalid cases
	glgl->equip(NULL);
	glgl->unequip(-1);
	glgl->unequip(4);
	glgl->unequip(3);

	glgl->use(0, *glgl);
	// Unequip element
	glgl->unequip(0);

	// Add to much element
	tmp = src->createMateria("cure");
	glgl->equip(tmp);
	tmp = src->createMateria("cure");
	glgl->equip(tmp);
	tmp = src->createMateria("cure");
	glgl->equip(tmp);

	// Try to use
	glgl->use(0, *glgl);
	glgl->use(5, *glgl);
	glgl->use(-1, *glgl);

	glgl->unequip(0);
	glgl->unequip(1);
	glgl->unequip(1);
	glgl->unequip(2);

	for (int i = 0; i < 10; i++) {
		if (Character::floor[i])
			delete(Character::floor[i]);
	}

	delete(glgl);
	delete(src);
	return 0;
}
