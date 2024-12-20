/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:16:54 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 12:56:34 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int	main( void )
{
	/*
	 * Test some valid and basic cases
	 */
	try
	{
		std::cout << "* Basic Tests *" << std::endl;
		Bureaucrat	loli = Bureaucrat("loli", 150);
		Bureaucrat	gg = Bureaucrat("gg", 5);

		std::cout << loli << std::endl;
		std::cout << gg << std::endl;
		
		loli.incrementGrade();
		std::cout << loli << std::endl << std::endl;

		gg.incrementGrade();
		std::cout << gg << std::endl;
		gg.incrementGrade();
		std::cout << gg << std::endl;
		gg.incrementGrade();
		std::cout << gg << std::endl;
		gg.incrementGrade();
		std::cout << gg << std::endl;

		/*
		 * Try to increment gg one more time
		 */
		gg.incrementGrade();
		std::cout << gg << std::endl;

		std::cout << "*** Shouldn't be print *** " << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	/*
	 * Grade too low decrment test
	 */
	std::cout << std::endl;
	try
	{
		std::cout << "Try to get below the lowest grade" << std::endl;
		Bureaucrat	rambo = Bureaucrat("rambo", 150);
		std::cout << rambo << std::endl;
		rambo.decrementGrade();

		std::cout << "*** Shouldn't be print" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	/*
	 * Test constructors errors
	 */
	std::cout << std::endl;
	try
	{
		std::cout << "* Test to make Bureaucrat with invalid grades *" << std::endl;
		std::cout << "> Valid instance"  << std::endl;
		Bureaucrat	rambo = Bureaucrat("rambo", 150);
		std::cout << rambo << std::endl;
		std::cout << "> Invalid instance Bureaucrat(\"Josekin\", 0)"  << std::endl;
		Bureaucrat josekin = Bureaucrat("Josekin", 0);

		std::cout << "*** Shouldn't be print" << std::endl;
		std::cout << josekin << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "> Invalid instance Bureaucrat(\"Josekin\", -4)"  << std::endl;
		Bureaucrat josekin = Bureaucrat("Josekin", -4);

		std::cout << "*** Shouldn't be print" << std::endl;
		std::cout << josekin << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "> Invalid instance Bureaucrat(\"Josekin\", 151)"  << std::endl;
		Bureaucrat josekin = Bureaucrat("Josekin", 151);

		std::cout << "*** Shouldn't be print" << std::endl;
		std::cout << josekin << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "*** TEST END ***" << std::endl;
	return (0);
}
