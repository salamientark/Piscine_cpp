/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 08:44:23 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 21:04:53 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <ostream>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm {
	public:
		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class ExecGradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		AForm( void );	// Canonical
		AForm( AForm const & rhs ); // Canonical
		AForm( std::string const name);
		AForm( std::string const name, int const sign_grade, int const exec_grade);
		virtual ~AForm(); // Canonical

		AForm&				operator=( AForm const & rhs ); // Canonical

		std::string const	getName( void ) const;
		bool				getSigned( void ) const;
		int				 	getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void				beSigned( const Bureaucrat& rhs );
		virtual void		execute( const Bureaucrat& executor ) const = 0;

	private:
		std::string const	_name;
		bool				_signed;
		int const			_sign_grade;
		int const			_exec_grade;
};

std::ostream&	operator<<( std::ostream& os, const AForm& rhs );

#endif // !AFORM_HPP
