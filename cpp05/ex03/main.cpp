/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:16:54 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 21:23:16 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <ostream>

int	main( void )
{

	/*
	 * Try Basic test
	 */
	try
	{
		Bureaucrat	admin = Bureaucrat("admin", 1);
		Bureaucrat	newbie = Bureaucrat("newbie", 149);
		ShruberryCreationForm	shrub = ShruberryCreationForm("yaya");
		RobotomyRequestForm		robo = RobotomyRequestForm("josuine");
		PresidentialPardonForm	pres = PresidentialPardonForm("john rambo");

		std::cout << std::string(80, '*') << std::endl;
		std::cout << "* Testing basic cases *" << std::endl;
		admin.signForm(shrub);
		admin.signForm(robo);
		admin.signForm(pres);
		admin.signForm(robo);

		std::cout << admin << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robo << std::endl;
		std::cout << pres << std::endl;

		admin.executeForm(shrub);
		admin.executeForm(pres);
		admin.executeForm(robo);
		admin.executeForm(robo);
		admin.executeForm(robo);
		admin.executeForm(robo);
		admin.executeForm(robo);
		admin.executeForm(robo);
		admin.executeForm(robo);

		std::cout << std::endl << std::string(80, '*') << std::endl;
		std::cout << "* Testing not sufficient exec grade *" << std::endl;
		std::cout << newbie << std::endl;
		newbie.executeForm(pres);

		std::cout << "*** SHOULD NOT APPEAR ***" << std::endl;
	}
	catch  (std::exception& e)
	{
		std::cout << std::endl;
		// delete(shrub);
		// delete(robo);
		// delete(pres);
	}

	/*
	 * Trying to execute not signed form
	 */
	try
	{
		Bureaucrat	admin = Bureaucrat("admin", 1);
		Bureaucrat	newbie = Bureaucrat("newbie", 149);
		ShruberryCreationForm	shrub = ShruberryCreationForm("yaya");
		RobotomyRequestForm		robo = RobotomyRequestForm("josuine");
		PresidentialPardonForm	pres = PresidentialPardonForm("john rambo");

		std::cout << std::endl << std::string(80, '*') << std::endl;
		std::cout << "* Testing Form not signed *" << std::endl;
		admin.signForm(shrub);
		admin.signForm(robo);
		admin.signForm(robo);

		std::cout << admin << std::endl;
		std::cout << robo << std::endl;
		admin.executeForm(pres);
		
		std::cout << "*** SHOULD NOT APPEAR ***" << std::endl;
	}
	catch  (std::exception& e)
	{
		std::cout << std::endl;
	}

	return (0);
}
