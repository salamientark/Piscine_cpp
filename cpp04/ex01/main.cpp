/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:00:41 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 09:15:29 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include <ios>

int main()
{
	// Subject test
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	// Own test part
	std::cout << std::endl;

	Dog* a = new Dog();
	Dog* b = new Dog(*a);

	Dog *c = new Dog();

	delete a;
	delete b;
	delete c;

	std::cout << std::endl;
	
	const Animal*	array[6]; // Create an animal array

	for (int i = 0; i < 3; i++){	// Fill one part of the array
		array[i] = new Dog();	// with newly allocated dogs
		std::cout << std::endl;
	}
								//
	for (int i = 3; i < 6; i++){	// Fill the other part of the array
		array[i] = new Cat();	// with newly allocated cats
		std::cout << std::endl;
	}

	// Check if alement are deep copy by printing adrees and pointed adress
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Adresse of array[" << i << "] : " << std::hex << array[i]
			<< " --> " << array[i]->getType() << std::endl;
	}
	std::cout << std::endl;

	// Freeing memory
	for (int i = 0; i < 6; i++){
		delete(array[i]);
		std::cout << std::endl;
	}

	return 0;
}
