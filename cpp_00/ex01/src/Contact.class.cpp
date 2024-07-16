#include <cctype>
#include <iostream>
#include "Contact.class.hpp"

using namespace std;

Contact::Contact()
	: f_name(""), l_name(""), n_name(""), phone_nbr(""), dark_secret("")
{
	
}

Contact::Contact (string fn, string ln, string nn, std::string pn, string ds)
	: f_name(fn), l_name(ln), n_name(nn), phone_nbr(pn), dark_secret(ds)
{
}

Contact::~Contact(void)
{
}

int	is_valid_name(std::string str)
{
	int	len;

	len = str.length();
	for(int i = 0; i < len; i++)
	{
		if (str[i] != '-'
			&& !((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
				return (0);
	}
	return (1);
}

int	is_valid_phone_nbr(std::string phone_nbr)
{
	int	len;

	len = phone_nbr.length();
	if (len < 4 || len > 15)
		return (0);
	for (int i = 0; i < len; i++)
		if (!std::isdigit(phone_nbr[i])) return (0);
	return (1);
}

void	Contact::fill_contact()
{
	do
	{
		cout << "Enter contact FIRST_NAME." << endl << "-$> ";
		cin >> this->f_name;
	}while (!is_valid_name(this->f_name));
	do
	{
		cout << "Enter contact LAST_NAME." << endl << "-$> ";
		cin >> this->l_name;
	}while (!is_valid_name(this->l_name));
	cout << "Enter contact NICKNAME." << endl << "-$> ";
	cin >> this->n_name;
	do {
		cout << "Enter contact PHONE_NBR." << endl << "-$> ";
		cin >> this->phone_nbr;
	}while (!is_valid_phone_nbr(this->phone_nbr));
	cout << "Enter contact DARKEST_SECRET." << endl << "-$> ";
	cin >> this->dark_secret;
}
