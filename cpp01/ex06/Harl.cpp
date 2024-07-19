/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:44:44 by madlab            #+#    #+#             */
/*   Updated: 2024/07/20 00:12:21 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <iterator>
#include <ostream>

Harl::Harl( void )
{
	this->msg_l[0] = std::pair<std::string, Harlmfp>("DEBUG", &Harl::debug);
	this->msg_l[1] = std::pair<std::string, Harlmfp>("INFO", &Harl::info);
	this->msg_l[2] = std::pair<std::string, Harlmfp>("WARNING", &Harl::warning);
	this->msg_l[3] = std::pair<std::string, Harlmfp>("ERROR", &Harl::error);
}

Harl::~Harl( void )
{

}

void	Harl::debug( void ) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "please don't use a standard debuf message for debugging" << std::endl;
}

void	Harl::info( void ) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "This message is very informative" << std::endl;
}

void	Harl::warning( void ) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Be carreful !" << std::endl;
}

void	Harl::error( void ) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "WHAT HAVE YOU DONE !!!" << std::endl;
}

void	Harl::complain( std::string level ) const
{
	int	i = 0;
	int	ref = 4;

	while (i < 4)
	{
		if (level.compare(this->msg_l[i].first) == 0)
			ref = i;
		if (i >= ref)
		{
			(this->*msg_l[i].second)();
			std::cout << std::endl;
		}
		i++;
	}
	if (ref == 4)
		std::cout << "[ Yeah Yeah Yeah ... ! ]" << std::endl;
}
