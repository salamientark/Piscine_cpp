/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:06:14 by madlab            #+#    #+#             */
/*   Updated: 2024/07/20 00:09:16 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Realy ?!" << std::endl;
		std::cout << "Enter an argument" << std::endl;
		return (0);
	}
	Harl	badboy;

	badboy.complain(av[1]);
	return (0);
}
