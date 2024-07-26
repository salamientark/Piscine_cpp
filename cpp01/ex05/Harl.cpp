/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:21:41 by madlab            #+#    #+#             */
/*   Updated: 2024/07/24 07:40:49 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

// ************************************************************************** //
//                        Constructor & Destructor                            //
// ************************************************************************** //

Harl::Harl( void )
{
	this->fct_lst[0] = std::pair<std::string, HarlFctPtr>("DEBUG", &Harl::debug);
	this->fct_lst[1] = std::pair<std::string, HarlFctPtr>("INFO", &Harl::info);
	this->fct_lst[2] = std::pair<std::string, HarlFctPtr>("WARNING", &Harl::warning);
	this->fct_lst[3] = std::pair<std::string, HarlFctPtr>("ERROR", &Harl::error);
}

Harl::~Harl( void )
{

}

// ************************************************************************** //
//                            Member functions                                //
// ************************************************************************** //

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++) {
		if (this->fct_lst[i].first == level)
		{
			std::cout << "[ " + this->fct_lst[i].first + " ]" << std::endl;
			(this->*(fct_lst[i].second))();
			std::cout << std::endl;
		}
	}
}
