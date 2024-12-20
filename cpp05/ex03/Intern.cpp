/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:32:12 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 13:18:36 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"



/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Intern::Intern( void )
{
	return ;
}

Intern::Intern( Intern const & rhs )
{
	*this = rhs;
	return ;
}

Intern::~Intern( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Intern&	Intern::operator=( Intern const & rhs )
{
	(void) rhs;
	if (this == &rhs)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
AForm*	Intern::makeShruberryForm( std::string target ) const
{
	try {
		AForm*	new_form = new ShruberryCreationForm(target);
		return (new_form);
	}
	catch (const std::exception& e) {
		std::cerr << "** Intern couldn't create " << target
			<< " ShruberryCreationForm because " << e.what();
		throw (std::exception());
	}
}

AForm*	Intern::makeRobotomyForm( std::string target ) const
{
	try {
		AForm*	new_form = new RobotomyRequestForm(target);
		return (new_form);
	}
	catch (const std::exception& e) {
		std::cerr << "** Intern couldn't create " << target
			<< " RobotomyRequestForm because " << e.what();
		throw (std::exception());
	}
}

AForm*	Intern::makePresidentialForm( std::string target ) const
{
	try {
		AForm*	new_form = new PresidentialPardonForm(target);
		return (new_form);
	}
	catch (const std::exception& e) {
		std::cerr << "** Intern couldn't create " << target
			<< " PresidentialPardonForm because " << e.what();
		throw (std::exception());
	}
}

AForm*	Intern::makeForm( std::string name, std::string target )
{
	AForm* res;

	static const std::string	_form_name_[3] = {"shruberry creation",
		"robotomy request", "presidential pardon"};

	static AForm* (Intern::*_form_func_[3])(std::string target) const =
		{&Intern::makeShruberryForm, &Intern::makeRobotomyForm,
			&Intern::makePresidentialForm };
	for (int i = 0; i < 3; i++)
	{
		if (name.compare(_form_name_[i]) == 0){
			res = ((this->*_form_func_[i])(target));
			std::cout << "Intern creates " << name << std::endl;
			return (res);
		}
	}
	std::cerr << "Unknow formtype name : " << name << std::endl;
	return (NULL);
}
