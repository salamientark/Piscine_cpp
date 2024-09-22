/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:56:34 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 21:02:19 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# define NAME_SHRUBERRY "shruberry"
# define SIGN_SHRUBERRY 145
# define EXEC_SHRUBERRY 137
# define ASCII_TREE "\
       _-_\
    /~~   ~~\\\
 /~~         ~~\\
\{               }\
 \\  _-     -_  /\
   ~  \\\\ //  ~\
_- -   | | _- _\
  _ -  | |   -_\
      // \\\\\
"

# include <fstream>
# include "AForm.hpp"

class ShruberryCreationForm :public AForm {
	public:
		ShruberryCreationForm( void );
		ShruberryCreationForm( ShruberryCreationForm const & rhs );
		~ShruberryCreationForm();
		ShruberryCreationForm( std::string target );

		ShruberryCreationForm&	operator=( ShruberryCreationForm const & rhs );

		std::string				getTarget( void ) const;

		void					beSigned( const Bureaucrat& rhs );
		void					execute( const Bureaucrat& executor ) const;

	private:
		std::string				_target;
		
};

std::ostream&		operator<<( std::ostream& os, const ShruberryCreationForm& rhs );

#endif // !SHRUBERRYCREATIONFORM_HPP
