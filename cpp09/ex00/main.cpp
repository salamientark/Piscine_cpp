/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:48:30 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 09:37:47 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>

int	main(int ac, char *av[]) {
	(void) ac;
	(void) av;
	try {
		BitcoinExchange	db;
	} catch(std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}
