/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:33:02 by madlab            #+#    #+#             */
/*   Updated: 2024/07/16 15:33:03 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

using namespace std;

int	main()
{
	Phonebook	book;
	string		input;	

	do
	{
		cout << "$> ";
		std::getline(std::cin, input);
		if (std::cin.eof() == 1)
		{
			std::cout << std::endl;
			break ;
		}
		else if (input.compare("ADD") == 0)
			book.add_contact();
		else if (input.compare("SEARCH") == 0)
			book.search_contact();
		else {} 
	} while (input.compare("EXIT") != 0);
	cout << "Bye Bye !" << endl;
	return (0);
}
