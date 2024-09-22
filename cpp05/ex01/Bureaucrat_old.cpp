/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:37 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 10:10:41 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const	char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::Grade is too high.");
}

const	char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::Grade is too low.");
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

Bureaucrat::Bureaucrat( std::string name ,int grade ) throw()
	: _name(name)
{
	try {
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << grade << " : " << e.what() << std::endl;
		this->_grade = 1;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << grade << " : " << e.what() << std::endl;
		this->_grade = 150;
	}
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
void	Bureaucrat::incrementGrade( void ) throw()
{
	try
	{
		if (this->_grade <= 1)
			throw (Bureaucrat::GradeTooHighException());
		this->_grade--;
		return ;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << this->_grade << " - 1 : " << e.what() << std::endl;
		return ;
	}
}

void	Bureaucrat::decrementGrade( void ) throw()
{
	try
	{
		if (this->_grade >= 150)
			throw (Bureaucrat::GradeTooLowException());
		this->_grade++;
		return ;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << this->_grade << " + 1 : " << e.what() << std::endl;
		return ;
	}
}

void	Bureaucrat::signForm( Form& form ) const throw()
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
