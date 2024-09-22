/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:42:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 12:18:09 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>
# include <exception>
# include <string>

class Bureaucrat {
	public:
		class GradeTooHighException : public std::exception {
			public :
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char*	what() const throw();
		};

		Bureaucrat( void );	// Canonical Form
		Bureaucrat( Bureaucrat const & rhs ); // Canonical Form
		Bureaucrat( std::string name, int grade );
		~Bureaucrat(); // Canonical Form

		Bureaucrat& operator=( Bureaucrat const & rhs ); // Canonical form

		std::string const	getName( void ) const;
		int					getGrade( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& rhs);

#endif // !BUREAUCRAT_HPP
