#include "Phonebook.class.hpp"
#include <iomanip>
#include <iostream>
#include <ostream>

Phonebook::Phonebook () : _last_index(0)
{
}

Phonebook::~Phonebook(void)
{
}

void	Phonebook::add_contact( void )
{
	Contact	c;

	this->_book[this->_last_index].fill_contact();
	this->_last_index = (this->_last_index + 1) % 8;	
}

void	Phonebook::display( void ) const
{
	std::cout << "+" << std::setfill('-') << std::setw(44) << "+" << std::endl
		<< std::setfill(' ');	
	for (int i = 0; i < 8; i++)
	{
		if (this->_book[i].f_name == "")
			break ;
		std::cout << "|" << std::setw(10) << i << "|"
			<< std::setw(10) << this->_book[i].f_name << "|"
			<< std::setw(10) << this->_book[i].l_name << "|"
			<< std::setw(10) << this->_book[i].n_name << "|" << std::endl;
	}
	std::cout << "+" << std::setfill('-') << std::setw(44) << "+" << std::endl
		<< std::setfill(' ');	
}

void	Phonebook::search_contact( void ) const
{
	this->display();
	return ;	
}
