/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:44:34 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 23:59:15 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>

int	main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "Please enter an expression as argument." << std::endl;
		return (1);
	}
	try {
		RPN			calculator;
		std::string	expr(av[1]);
		double		res = calculator.calculate(expr);

		std::cout << res << std::endl;
	}
	catch (RPN::InvalidExpressionException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	catch (std::exception& e) {
		std::cerr << "Error." << std::endl;
		return (1);
	}
	return (0);
}
