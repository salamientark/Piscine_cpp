/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:32:08 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/23 09:19:05 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG
# define DEBUG

#include "AForm.hpp"


class Intern {
	typedef AForm* (Intern::*const FormFuncPtr)( std::string ) const;
	public:
		Intern( void );
		Intern( Intern const & rhs );
		~Intern();

		Intern& operator=( Intern const & rhs );

		AForm*	makeForm( std::string name, std::string target);

	private:
		AForm*	makeShruberryForm( std::string target ) const;
		AForm*	makeRobotomyForm( std::string target ) const;
		AForm*	makePresidentialForm( std::string target ) const;

		static const std::string	_form_name_[3];
		// static const FormFuncPtr	_form_func_[3];
		// const static AForm* (Intern::*_form_func_[3])(std::string target) const;

	
};

#endif // !DEBUG
