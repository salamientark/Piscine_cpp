/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:44:44 by madlab            #+#    #+#             */
/*   Updated: 2024/10/07 16:43:48 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <utility>


Harl::Harl( void )
{
	this->_level[0] = std::pair<int, std::string>(0, "DEBUG");
	this->_level[1] = std::pair<int, std::string>(1, "INFO");
	this->_level[2] = std::pair<int, std::string>(2, "WARNING");
	this->_level[3] = std::pair<int, std::string>(3, "ERROR");
}

Harl::~Harl( void )
{

}

void	Harl::debug( void ) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "please don't use a standard debug message for debugging" << std::endl;
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

int		Harl::getLevelValue(const std::string level) const
{
	for (int i = 0; i < 4; i++)
	{
		if (level.compare(this->_level[i].second) == 0)
			return (i);
	}
	return (4);
}

void Harl::complain( std::string level ) const
{
	switch (this->getLevelValue(level)) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout << DEFAULT_MSG << std::endl;
			break;
	}
	return ;
}
