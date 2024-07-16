#include "Phonebook.class.hpp"
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

Phonebook::Phonebook () : _last_index(0), _size(0)
{
}

Phonebook::~Phonebook(void)
{
}

void	Phonebook::add_contact( void )
{
	Contact	c;

	this->_book[this->_last_index].fill_contact();
	if (this->_size < 8)
		this->_size++;
	this->_last_index = (this->_last_index + 1) % 8;	
	std::cin.ignore(1, '\n');
}

void	Phonebook::display_one_contact(int index) const
{
	int		size;

	size = std::max(this->_book[index].f_name.length(), this->_book[index].l_name.length());
	size = std::max(size, (int)this->_book[index].n_name.length());
	size = std::max(size, (int)this->_book[index].phone_nbr.length());
	size = std::max(size, (int)this->_book[index].dark_secret.length());
	std::cout << "+" << std::setfill('-') << std::setw(15) << "+" << std::setfill('-') << std::setw(size + 1) << "+" << std::endl
		<< "|" << std::setfill(' ') << std::setw(14) << "First Name" << "|"
			<< std::setw(size) << this->_book[index].f_name << "|" << std::endl
		<< "|" << std::setw(14) << "Last Name" << "|"
			<< std::setw(size) << this->_book[index].l_name << "|" << std::endl
		<< "|" << std::setw(14) << "Nickname" << "|"
			<< std::setw(size) << this->_book[index].n_name << "|" << std::endl
		<< "|" << std::setw(14) << "Phone Number" << "|"
			<< std::setw(size) << this->_book[index].phone_nbr << "|" << std::endl
		<< "|" << std::setw(14) << "Darkest Secret" << "|"
			<< std::setw(size) << this->_book[index].dark_secret << "|" << std::endl
		<< "+" << std::setfill('-') << std::setw(15) << "+" << std::setw(size + 1) << "+"<< std::endl;
	
}

void	trunc_word(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void	Phonebook::display( void ) const
{
	std::cout << "+" << std::setfill('-') << std::setw(44) << "+" << std::endl
		<< std::setfill(' ');	
	for (int i = 0; i < 8; i++)
	{
		if (this->_book[i].f_name == "")
			break ;
		std::cout << "|" << std::setw(10) << i << "|";
		trunc_word(this->_book[i].f_name);
		std::cout << "|";
		trunc_word(this->_book[i].l_name);
		std::cout << "|";
		trunc_word(this->_book[i].n_name);
		std::cout << "|" << std::endl;
	}
	std::cout << "+" << std::setfill('-') << std::setw(44) << "+" << std::endl
		<< std::setfill(' ');	
}

void	Phonebook::search_contact( void ) const
{
	std::string	input;
	int			index;

	this->display();
	if (this->_size == 0)
		return ;
	std::cout << "--$> ";
	std::cin >> input;
    std::istringstream(input) >> index;
	while (!std::isdigit(input[0]) || (index < 0 || index >= this->_size))
	{
		std::cout << "Invalid index !" << std::endl;
		std::cout << "--$> ";
		std::cin >> input;
		std::istringstream(input) >> index;
	}
	display_one_contact(index);
	std::cin.ignore(1, '\n');
	return ;	
}
