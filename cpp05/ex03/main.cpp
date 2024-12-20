/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:16:54 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 13:19:26 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int	main( void )
{
	// Subject test
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	std::cout << std::endl;


	Intern	john;
	AForm*	shrub;
	AForm*	robo; 	
	AForm*	pres; 	 
	AForm*	nul;
	Bureaucrat tops("tops", 50);

	try
	{
		/*
		 * Try Basic test
		 */
		std::cout << std::string(60, '*') << std::endl;
		std::cout << "Creating all forms" << std::endl;

		shrub = john.makeForm("shruberry creation", "yoyo");
		robo = john.makeForm("robotomy request", "robo");
		pres = john.makeForm("presidential pardon", "president");
		nul = john.makeForm("form", "oleg");

		std::cout << tops << std::endl;
		tops.signForm(*shrub);
		tops.signForm(*robo);
		tops.signForm(*pres);
		// shrub->beSigned(tops);
		// robo->beSigned(tops);
		// pres->beSigned(tops);
		(void) nul;

		tops.executeForm(*shrub);
		tops.executeForm(*robo);
		tops.executeForm(*pres);


		std::cout << "*** SHOULDN'T APPEAR ***" << std::endl;
		delete(shrub);
		delete(robo);
		delete(pres);

	}
	catch  (std::exception& e)
	{
		std::cout << std::endl;
		delete(shrub);
		delete(robo);
		delete(pres);
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
