/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:56:34 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 21:01:41 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# define NAME_PRESIDENTIAL "presidential"
# define SIGN_PRESIDENTIAL 25
# define EXEC_PRESIDENTIAL 5

# include "AForm.hpp"
#include <string>

class PresidentialPardonForm :public AForm {
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( PresidentialPardonForm const & rhs );
		~PresidentialPardonForm();
		PresidentialPardonForm( std::string target );

		PresidentialPardonForm&	operator=( PresidentialPardonForm const & rhs );

		std::string				getTarget( void ) const;

		void					execute( const Bureaucrat& executor ) const;

	private:
		std::string				_target;
		
};

std::ostream&	operator<<( std::ostream& os, const PresidentialPardonForm& rhs );

#endif // !PRESIDENTIALPARDONFORM_HPP
