/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:33:23 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 14:16:04 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarClass.hpp" 
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <set>
#include <sstream>
#include <stdexcept>

static int	is_param_valid( std::string str )
{
	int	len = str.length();
	int i;

	if (len == 0 || (len > 1 && !(std::isdigit(str[0]) || str[0] == '-' || str[0] == '+')))
		return (0);
	if (len == 1)
		return (1);
	i = (str[0] == '-' || str[0] == '+');
	while (i < len && std::isdigit(str[i])) { i++; };
	if (i == len || (i == len - 1 && (str[i] == '.' || str[i] == 'f')))
		return (1);
	if (str[i] != '.')
		return (0);
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

static void	convert_from_char(char& c, int& ival, float& fval, double& dval)
{
	ival = static_cast<int>(c);
	fval = static_cast<float>(ival);
	dval = static_cast<double>(fval);
	return ;
}

static void	convert_from_string( std::string param, int& ival,
	float& fval, double& dval, int& precision)
{
	std::stringstream	ss(param);
	size_t				decimal_pos = param.find('.');
	size_t				param_len = param.length();

	if (!(ss >> ival))
		throw (std::invalid_argument("it is an invalid agrument"));
	ss.clear();
	ss.seekg(0);
	if (!(ss >> fval))
		throw (std::invalid_argument("it is an invalid agrument"));
	ss.clear();
	ss.seekg(0);
	if (!(ss >> dval))
		throw (std::invalid_argument("it is an invalid agrument"));
	if (floor(dval) == dval || decimal_pos == param_len
			|| (param[param_len - 1] == 'f' && decimal_pos == param_len - 1))
		precision = 0;
	else
	 precision = param_len - decimal_pos - 1;
	return ;
}

static void	print_result(int ival, float fval, double dval, int precision)
{
	char	c = static_cast<char>(ival);

	std::cout << "char   : ";
	if (!std::isprint(c))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int    : " << ival << std::endl;

	std::ostringstream out;
	if (fval == 0)
		out << std::fixed << std::setprecision(0) << fval;
	else
		out << std::fixed << std::setprecision(precision) << fval;
	std::string str = out.str();
	if (fval != 0)
		str.erase(str.find_last_not_of('0') + 1, std::string::npos);

	std::cout << "float  : " << str;
	if (precision == 0)
		std::cout << ".0";
	std::cout << "f"<< std::endl;

	out.str("");
	out.clear();
	out << std::fixed << std::setprecision(precision) << dval;
	str = out.str();
	if (dval != 0)
		str.erase(str.find_last_not_of('0') + 1, std::string::npos);

	std::cout << "double : " << str;
	if (precision == 0)
		std::cout << ".0";
	std::cout << std::endl;

	return ;
}

void	ScalarClass::convert( std::string param )
{
	int		ival = 0;
	float	fval = 0;
	int		precision = 0;
	double	dval = 0;

	if (is_special_case(param))
		return ;
	if (!is_param_valid(param))
		throw (ScalarClass::InvalidParameterException());

	if (!isdigit(param[0]) && param.length() == 1)
		convert_from_char(param[0], ival, fval, dval);
	else
		convert_from_string( param, ival, fval, dval, precision);
	print_result(ival, fval, dval, precision);
}
