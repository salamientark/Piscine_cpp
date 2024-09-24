/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:42:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 11:03:20 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCLASS_HPP
# define SCALARCLASS_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>
# include <sstream>
# include <iomanip>
# include <cmath>
		

class ScalarClass {
	public:
		class InvalidParameterException : public std::exception {
			public :
				virtual const char*	what() const throw();
		};

		static  void	convert( std::string param );

	private:
		ScalarClass( void );	// Canonical Form
		ScalarClass( ScalarClass const & rhs ); // Canonical Form
		~ScalarClass(); // Canonical Form

		ScalarClass& operator=( ScalarClass const & rhs ); // Canonical form

};

#endif // !SCALARCLASS_HPP
