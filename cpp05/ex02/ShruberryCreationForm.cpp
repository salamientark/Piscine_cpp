/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:59:28 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 21:23:51 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
ShruberryCreationForm::ShruberryCreationForm( void )
	: AForm(NAME_SHRUBERRY, SIGN_SHRUBERRY, EXEC_SHRUBERRY), _target("")
{
	return ;
}

ShruberryCreationForm::ShruberryCreationForm( ShruberryCreationForm const & rhs )
	: AForm( rhs ), _target(rhs.getTarget())
{
	return ;
}

ShruberryCreationForm::ShruberryCreationForm( std::string const target)
	: AForm(NAME_SHRUBERRY, SIGN_SHRUBERRY, EXEC_SHRUBERRY), _target(target)
{
	return ;
}

ShruberryCreationForm::~ShruberryCreationForm( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::string				ShruberryCreationForm::getTarget( void ) const
{
	return (this->_target);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
ShruberryCreationForm&	ShruberryCreationForm::operator=( ShruberryCreationForm const & rhs )
{
	if (this == &rhs)
		return (*this);
	AForm::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}

std::ostream&		operator<<( std::ostream& os, const ShruberryCreationForm& rhs )
{
	os << rhs.getName() << " ShruberryCreationForm" << std::endl
		<< "Signed     : " << rhs.getSigned() << std::endl
		<< "Sign grade : " << rhs.getSignGrade() << std::endl
		<< "Exec grade : " << rhs.getExecGrade() << std::endl
		<< "Target     : " << rhs.getTarget() << std::endl;
	return (os);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void					ShruberryCreationForm::execute( const Bureaucrat& executor ) const
{
	std::ofstream	ofs;

	try
	{
		AForm::execute(executor);
		// if (this->getSigned() == 0)
		// 	throw (AForm::FormNotSignedException());
		// if (this->getExecGrade() < executor->getGrade())
		// 	throw (AForm::ExecGradeTooLowException());
		ofs.open(this->_target.c_str(), std::ios_base::trunc);
		if (!ofs.is_open())
			throw (std::exception());
		ofs << std::string(ASCII_TREE) << std::endl;
		ofs << std::string(ASCII_TREE);
		ofs.close();
	}
	catch (std::exception& e)
	{
		std::cerr << "couldn't open " << this->_target << " : " << e.what() << std::endl;
	}
}
