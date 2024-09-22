/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:51:19 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 18:40:20 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const	char*	AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::Grade is too high.");
}

const	char*	AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::Grade is too low.");
}

const	char*	AForm::FormNotSignedException::what() const throw()
{
	return ("AForm::Form not signed.");
}

const	char*	AForm::ExecGradeTooLowException::what() const throw()
{
	return ("AForm::Exec grade too low.");
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
AForm::AForm( void )
	: _name(""), _signed(0), _sign_grade(100), _exec_grade(50)
{
	return ;
}

AForm::AForm( AForm const & rhs )
	: _name(rhs.getName()), _signed(rhs.getSigned()),
		_sign_grade(rhs.getSignGrade()), _exec_grade(rhs.getExecGrade())
{
	return ;
}

AForm::AForm( std::string const name )
	: _name(name), _signed(0), _sign_grade(100), _exec_grade(50)
{
	return ;
}

AForm::AForm( std::string const name, int const sign_grade, int const exec_grade )
	: _name(name), _signed(0), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw (GradeTooHighException());
	if (_sign_grade > 150 || _exec_grade > 150)
		throw (GradeTooLowException());
}

AForm::~AForm( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string const	AForm::getName( void ) const
{
	return (this->_name);
}

bool				AForm::getSigned( void ) const
{
	return (this->_signed);
}

int					AForm::getSignGrade( void ) const
{
	return (this->_sign_grade);
}

int					AForm::getExecGrade( void ) const
{
	return (this->_exec_grade);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
AForm& AForm::operator=( AForm const & rhs )
{
	this->_signed = rhs.getSigned();
	return (*this);
}

std::ostream&	operator<<( std::ostream& os, const AForm& rhs)
{
	os << rhs.getName() << " AForm" << std::endl
		<< "Signed     : " << rhs.getSigned() << std::endl
		<< "Sign grade : " << rhs.getSignGrade() << std::endl
		<< "Exec grade : " << rhs.getExecGrade() << std::endl;
	return (os);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void			AForm::beSigned( const Bureaucrat& rhs )
{
	if (this->getSigned() == 1)
		return ;
	if (this->getSignGrade() < rhs.getGrade())
		throw (AForm::GradeTooLowException());
	this->_signed = 1;
}

void			AForm::execute( const Bureaucrat& executor ) const
{
	if (this->getSigned() == 0)
		throw (AForm::FormNotSignedException());
	if (this->getExecGrade() < executor.getGrade())
		throw (AForm::ExecGradeTooLowException());
}
