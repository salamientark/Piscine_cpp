/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:00:41 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 19:04:24 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include "WrongCat.hpp"
#include <ios>

int main()
{
	// Subject test
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	// Own test part
	
	// AAnimal	kok;					// Won't work because we can't
	// AAnimal*	kok = new AAnimal();	// initialize abstract class
	
	const AAnimal*	array[6]; // Create an animal array

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
			<< " --> " << array[i]->getType() << " ";
		array[i]->makeSound();
	}
	std::cout << std::endl;

	// Freeing memory
	for (int i = 0; i < 6; i++){
		delete(array[i]);
		std::cout << std::endl;
	}

	return 0;
}
