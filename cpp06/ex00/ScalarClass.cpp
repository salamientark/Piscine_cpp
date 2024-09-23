/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:37 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/23 20:22:10 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarClass.hpp"

const char*	ScalarClass::InvalidParameterException::what( void ) const throw()
{
	return ("Parameter is neither a char or int or float or double");
}

static int	is_param_valid( std::string str )
{
	int	len = str.length();
	int i = 0;

	if (len == 0 || (len > 1 && !std::isdigit(str[0])))
		return (0);
	if (len == 1)
		return (1);
	while (i < len && std::isdigit(str[i])) { i++; };
	if (i == len || (i == len - 1 && (str[i] == '.' || str[i] == 'f')))
		return (1);
	if (str[i] != '.')
		return (1);
	i++;
	while (i < len && std::isdigit(str[i])) { i++; };
	return (i == len || (i == len - 1 && str[i] == 'f'));
}

static void	print_special_case( std::string float_val, std::string double_val )
{
	std::cout << "char   : impossible" << std::endl
		<< "int    : impossible" << std::endl
		<< "float  : " << float_val << std::endl
		<< "double : " << double_val << std::endl;
}

static int	is_special_case( std::string param )
{
	std::string	special_case[6] =
		{"nanf", "-inff", "+inff", "nan", "-inf", "+inf" };
	for (int i = 0; i < 6; i++)
	{
		if (param.compare(special_case[i]) == 0) {
			if (i > 2)
				print_special_case(special_case[i - 3], special_case[i] );
			else
				print_special_case(special_case[i], special_case[i + 3] );
			return (1);
		}
	}
	return (0);
}

static void	print_result(int ival, float fval, double dval)
{
	char	c = static_cast<char>(ival);

	std::cout << "char   : " << c << std::endl
			<< "int    : " << ival << std::endl
			<< "float  : " << fval << std::endl
			<< "double : " << dval << std::endl;
		
}

void	ScalarClass::convert( std::string param )
{
	int		ival;
	float	fval;
	double	dval;

	if (is_special_case(param))
		return ;
	if (is_param_valid(param))
		throw (ScalarClass::InvalidParameterException());

	ival = std::stoi(param);
	fval = std::stof(param); // Throw eith std::invalid_argument
							 // or std::out_of_range
	dval = std::stod(param); // Same as std::stof
	print_result(ival, fval, dval);
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
ScalarClass::ScalarClass( void )
{
	return ;
}

ScalarClass::ScalarClass( ScalarClass const & rhs )
{
	return ;
}

ScalarClass::~ScalarClass( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
ScalarClass& ScalarClass::operator=( ScalarClass const & rhs )
{
	return (*this);
}


/* ************************************************************************** */
/*                             Public Member Function                         */
