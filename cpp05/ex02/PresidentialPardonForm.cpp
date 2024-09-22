/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:59:28 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 21:21:22 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm(NAME_PRESIDENTIAL, SIGN_PRESIDENTIAL, EXEC_PRESIDENTIAL), _target("")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs )
	: AForm( rhs ), _target(rhs.getTarget())
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const target)
	: AForm(NAME_PRESIDENTIAL, SIGN_PRESIDENTIAL, EXEC_PRESIDENTIAL), _target(target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string				PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
PresidentialPardonForm&	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if (this == &rhs)
		return (*this);
	AForm::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}

std::ostream&		operator<<( std::ostream& os, const PresidentialPardonForm& rhs )
{
	os << rhs.getName() << " PresidentialPardonForm" << std::endl
		<< "Signed     : " << rhs.getSigned() << std::endl
		<< "Sign grade : " << rhs.getSignGrade() << std::endl
		<< "Exec grade : " << rhs.getExecGrade() << std::endl
		<< "Target     : " << rhs.getTarget() << std::endl;
	return (os);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void					PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
	AForm::execute(executor);
	// if (this->getSigned() == 0)
	// 	throw (AForm::FormNotSignedException());
	// if (this->getExecGrade() < executor->getGrade())
	// 	throw (AForm::ExecGradeTooLowException());
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
