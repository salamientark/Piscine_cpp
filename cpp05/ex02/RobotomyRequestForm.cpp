/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:16:34 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 21:23:42 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm(NAME_ROBOTOMY, SIGN_ROBOTOMY, EXEC_ROBOTOMY), _target("")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs )
	: AForm( rhs ), _target(rhs.getTarget())
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const target)
	: AForm(NAME_ROBOTOMY, SIGN_ROBOTOMY, EXEC_ROBOTOMY), _target(target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string				RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
RobotomyRequestForm&	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if (this == &rhs)
		return (*this);
	AForm::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}

std::ostream&		operator<<( std::ostream& os, const RobotomyRequestForm& rhs )
{
	os << rhs.getName() << " RobotomyRequestForm" << std::endl
		<< "Signed     : " << rhs.getSigned() << std::endl
		<< "Sign grade : " << rhs.getSignGrade() << std::endl
		<< "Exec grade : " << rhs.getExecGrade() << std::endl
		<< "Target     : " << rhs.getTarget() << std::endl;
	return (os);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void					RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
	AForm::execute(executor);
	// if (this->getSigned() == 0)
	// 	throw (AForm::FormNotSignedException());
	// if (this->getExecGrade() < executor->getGrade())
	// 	throw (AForm::ExecGradeTooLowException());
	static bool initialized = false;
	if (!initialized)
	{
		std::srand(std::time(NULL));
		initialized = true;
	}
	if (rand() % 2)
		std::cout << this->_target << " have been ROBOTOMIZED!!!" << std::endl;
	else
		std::cout << this->_target << "... Nothing happened" << std::endl;
	return ;
}
