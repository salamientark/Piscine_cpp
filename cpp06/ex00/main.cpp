/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:16:54 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/23 20:18:51 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarClass.hpp"

int	main( int ac, char **av )
{
	if (ac == 1) {
		std::cerr << "This program need an argument" << std::endl;
		return (0);
	}
	if (ac > 2) {
		std::cerr << "This program uses one argument only" << std::endl;
		return (0);
	}
	try{
		ScalarClass::convert(av[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << av[1] << " canno't be converted because "
			<< e.what() << std::endl;
	}
	return (0);
}
