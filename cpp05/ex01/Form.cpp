/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:51:19 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 13:20:52 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const	char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form::Grade is too high.");
}

const	char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form::Grade is too low.");
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Form::Form( void )
	: _name(""), _signed(0), _sign_grade(100), _exec_grade(50)
{
	return ;
}

Form::Form( Form const & rhs )
	: _name(rhs.getName()), _signed(rhs.getSigned()),
		_sign_grade(rhs.getSignGrade()), _exec_grade(rhs.getExecGrade())
{
	return ;
}

Form::Form( std::string const name )
	: _name(name), _signed(0), _sign_grade(100), _exec_grade(50)
{
	return ;
}

Form::Form( std::string const name, int const sign_grade, int const exec_grade )
	: _name(name), _signed(0), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw (GradeTooHighException());
	if (_sign_grade > 150 || _exec_grade > 150)
		throw (GradeTooLowException());
}

Form::~Form( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string const	Form::getName( void ) const
{
	return (this->_name);
}

bool				Form::getSigned( void ) const
{
	return (this->_signed);
}

int					Form::getSignGrade( void ) const
{
	return (this->_sign_grade);
}

int					Form::getExecGrade( void ) const
{
	return (this->_exec_grade);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Form& Form::operator=( Form const & rhs )
{
	this->_signed = rhs.getSigned();
	return (*this);
}

std::ostream&	operator<<( std::ostream& os, const Form& rhs)
{
	os << rhs.getName() << " Form" << std::endl
		<< "Signed     : " << rhs.getSigned() << std::endl
		<< "Sign grade : " << rhs.getSignGrade() << std::endl
		<< "Exec grade : " << rhs.getExecGrade() << std::endl;
	return (os);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void			Form::beSigned( const Bureaucrat& rhs )
{
	if (this->getSigned() == 1)
	{
		std::cout << "Form already signed" << std::endl;
		return ;
	}
	if (this->getSignGrade() < rhs.getGrade())
		throw (Form::GradeTooLowException());
	this->_signed = 1;
}
