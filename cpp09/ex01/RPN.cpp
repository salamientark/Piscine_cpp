/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:34:49 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/03 10:40:32 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstddef>
#include <cstring>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <string>

const char*	RPN::InvalidExpressionException::what() const throw() {
	return ("Invalid expression.");
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
RPN::RPN( void ) : _stack(std::stack<double>())
{
	return ;
}

RPN::RPN( RPN const & rhs )
	: _stack(rhs.getStack())
{
	return ;
}

RPN::~RPN( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::stack<double>	RPN::getStack( void ) const {
	return (this->_stack);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
RPN& RPN::operator=( RPN const & rhs )
{
	if (this != &rhs) {
		this->_stack = rhs.getStack();
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
void	RPN::_addNumber(const std::string& str) {
	std::stringstream	s(str);
	double				value;

	if (!(s >> value))
		throw (RPN::InvalidExpressionException());
	char c;
	if (s >> c)
		throw (RPN::InvalidExpressionException());
	this->_stack.push(value);
}

void	RPN::_do_op(const std::string& op) {
	double	rhs;
	double	lhs;
	double	res;

	if (this->_stack.size() < 2)
		throw (InvalidExpressionException());
	rhs = this->_stack.top();
	this->_stack.pop();
	lhs = this->_stack.top();
	this->_stack.pop();
	switch (op[0]) {
		case '+' :
			res = lhs + rhs;
			break ;
		case '-' :
			res = lhs - rhs;
			break ;
		case '*' :
			res = lhs * rhs;
			break ;
		case '/' :
			res = lhs / rhs;
			break ;
		default :
			throw (RPN::InvalidExpressionException());
	}
	this->_stack.push(res);
}


static bool	is_operator(const std::string& str) {
	if (str.size() == 1) {
		switch (str[0]) {
			case '+' :
			case '-' :
			case '*' :
			case '/' :
				return (true);
			default :
				return (false);
		}
	}
	return (false);
}

double	RPN::calculate( const std::string& expr ) {
	const char*	delimiter = " \t\n\v\f\r";
	size_t		len = expr.length();
	size_t		word_begin = 0;
	size_t		pos;
	std::string	tmp;

	while (word_begin < len && std::isspace(expr[word_begin]))
		word_begin++;
	pos = expr.find_first_of(delimiter, word_begin);
	while (word_begin != std::string::npos) {
		if (pos != word_begin) {
			tmp = expr.substr(word_begin, pos - word_begin);
			if (is_operator(tmp))
				this->_do_op(tmp);
			else
				this->_addNumber(tmp);
			word_begin = pos;
		}
		else
			word_begin = pos + 1;
		pos = expr.find_first_of(delimiter, word_begin);
	}
	if (this->_stack.size() != 1)
		throw (RPN::InvalidExpressionException());
	return (this->_stack.top());
}
