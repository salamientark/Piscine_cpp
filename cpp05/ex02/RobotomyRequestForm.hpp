/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:56:34 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 21:01:13 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# define NAME_ROBOTOMY "robotomy"
# define SIGN_ROBOTOMY 72
# define EXEC_ROBOTOMY 45

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm :public AForm {
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( RobotomyRequestForm const & rhs );
		~RobotomyRequestForm();
		RobotomyRequestForm( std::string target );

		RobotomyRequestForm&	operator=( RobotomyRequestForm const & rhs );

		std::string				getTarget( void ) const;

		// void					beSigned( const Bureaucrat& rhs );
		void					execute( const Bureaucrat& executor ) const;

	private:
		std::string						_target;
		static const bool				_random_seed;
		
};

std::ostream&	operator<<( std::ostream& os, const RobotomyRequestForm& rhs );

#endif // !ROBOTOMYREQUESTFORM_HPP
