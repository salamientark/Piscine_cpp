/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:16:54 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 13:25:50 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <ostream>

int	main( void )
{

	/*
	 * Try Basic test
	 */
	try
	{
		std::cout << "> Some valid tests" << std::endl;
		Bureaucrat	gg = Bureaucrat("gg", 50);
		Form		ddl = Form("ddl");
		Form		edl = Form("edl", 10, 20);

		std::cout << gg << std::endl;
		std::cout << ddl << std::endl;
		std::cout << edl << std::endl;

		gg.signForm(ddl);
		std::cout << ddl << std::endl;

		std::cout << std::endl << "* Invalid test part *" << std::endl;
		std::cout << "> gg try to sign edl" << std::endl;
		gg.signForm(edl);

		std::cout << "*** THIS LINE SHOULD NOT APPEAR ***" << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	/*
	 * Test Invalid form construcors
	 */
	try
	{
		std::cout << std::endl << "> Invalid Form constructor <" << std::endl;
		std::cout << "> Trying Form(\"aaa\", 0, 100)" << std::endl;
		Form aaa = Form("aaa", 0, 100);

		std::cout << "*** THIS LINE SHOULD NOT APPEAR ***" << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "> Invalid Form constructor <" << std::endl;
		std::cout << "> Trying Form(\"aaa\", 100, -1)" << std::endl;
		Form aaa = Form("aaa", 100, -1);

		std::cout << "*** THIS LINE SHOULD NOT APPEAR ***" << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "> Invalid Form constructor <" << std::endl;
		std::cout << "> Trying Form(\"aaa\", 1000, 4)" << std::endl;
		Form aaa = Form("aaa", 1000, 4);

		std::cout << "*** THIS LINE SHOULD NOT APPEAR ***" << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "> Invalid Form constructor <" << std::endl;
		std::cout << "> Trying Form(\"aaa\", 4, 1000)" << std::endl;
		Form aaa = Form("aaa", 4, 1000);

		std::cout << "*** THIS LINE SHOULD NOT APPEAR ***" << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << std::endl << "> Invalid Form constructor <" << std::endl;
		std::cout << "> Trying Form(\"aaa\", -45, 4100)" << std::endl;
		Form aaa = Form("aaa", -45, 4100);

		std::cout << "*** THIS LINE SHOULD NOT APPEAR ***" << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	/*
	 * Test invalid beSigned
	 */
	try
	{
		std::cout << std::endl << "Try invalid beSigned" << std::endl;
		Bureaucrat beber = Bureaucrat("beber", 149);
		Form		vaz_y_beber_signe = Form("vaz_y_beber_signe", 148, 148);

		std::cout << beber << std::endl
			<< vaz_y_beber_signe << std::endl;
		std::cout << "> Beber will try to change signed status" << std::endl;
		vaz_y_beber_signe.beSigned(beber);

		std::cout << "*** THIS LINE SHOULD NOT APPEAR ***" << std::endl;
	}
	catch  (Form::GradeTooLowException& e)
	{
		std::cout << "Beber couldn't make it " << e.what() << std::endl;
	}

	/*
	 * Test invalid signForm
	 */
	try
	{
		std::cout << std::endl << "Try invalid signForm" << std::endl;
		Bureaucrat beber = Bureaucrat("beber", 149);
		Form		vaz_y_beber_signe = Form("vaz_y_beber_signe", 148, 148);

		std::cout << beber << std::endl
			<< vaz_y_beber_signe << std::endl;
		std::cout << "> Beber will try again to sign form" << std::endl;
		beber.signForm(vaz_y_beber_signe);
		
		std::cout << "*** THIS LINE SHOULD NOT APPEAR ***" << std::endl;
	}
	catch  (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
