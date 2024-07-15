#include "Phonebook.class.hpp"
#include <iostream>
#include <ostream>
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
