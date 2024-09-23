/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:37 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/23 09:50:44 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

const	char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const	char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Bureaucrat::Bureaucrat( void ) : _name(""), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs )
	: _name(rhs.getName()), _grade(rhs.getGrade())
{
	return ;
}

Bureaucrat::Bureaucrat( std::string name ,int grade )
	: _name(name), _grade(grade)
{
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string const	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Bureaucrat& Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << " bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
	return ;
}

void	Bureaucrat::signForm( AForm& form ) const
{
	if (form.getSigned() == 1)
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
			<< " because it's already signed" << std::endl;
		return ;
	}
	if (form.getSignGrade() < this->getGrade())
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
			<< " because AForm::grade too low.";
		throw(AForm::GradeTooLowException());
	}
	form.beSigned(*this);
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm( const AForm& form )
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	// catch (AForm::ExecGradeTooLowException& e)
	catch (std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName()
			<< " because " << e.what();
		throw (e);
	}
}
