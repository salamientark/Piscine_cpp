/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:48:30 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 18:06:42 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>

int	main(int ac, char *av[]) {
	try {
		if (ac != 2)
			throw (BitcoinExchange::BadFileException());
		BitcoinExchange	db;
		db.compare(av[1]);
	} catch(std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
