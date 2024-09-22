/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:44:23 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 12:45:11 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <ostream>
# include <iostream>
# include <string>
// # include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		Form( void );	// Canonical
		Form( Form const & rhs ); // Canonical
		Form( std::string const name);
		Form( std::string const name, int const sign_grade, int const exec_grade);
		~Form(); // Canonical

		Form& operator=( Form const & rhs ); // Canonical

		std::string const	getName( void ) const;
		bool				getSigned( void ) const;
		int				 	getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void				beSigned( const Bureaucrat& rhs );

	private:
		std::string const	_name;
		bool				_signed;
		int const			_sign_grade;
		int const			_exec_grade;
};

std::ostream&	operator<<( std::ostream& os, const Form& rhs );

#endif // !FORM_HPP
