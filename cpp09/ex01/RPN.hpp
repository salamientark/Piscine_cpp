/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:07:22 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 23:54:47 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <iostream>
# include <stack>
# include <cstring>

class RPN {
public:
	class InvalidExpressionException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	RPN( void );
	RPN( RPN const & rhs );
	~RPN();

	RPN&				operator=( RPN const & rhs );

	std::stack<double>	getStack( void ) const;

	double				calculate( const std::string& expr );

private:
	std::stack<double>	_stack;

	void				_do_op(const std::string& op);
	void				_addNumber(const std::string& str);

};

#endif // !RPN_HPP
