/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:34:49 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 10:45:20 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <cctype>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>

const char*	BitcoinExchange::BadInputException::what() const throw() {
	return ("bad input");
}

const char*	BitcoinExchange::BadFileException::what() const throw() {
	return ("could not open file");
}

static bool	is_number(const std::string& str) {
	bool					decimal = false;
	std::string::const_iterator	it = str.begin();

	while (it != str.end()) {
		if (*it == '.') {
			if (decimal == true)
				return (false);
			decimal = true;
			it++;
			continue ;
		}
		if (!isdigit(*it))
			return (false);
		it++;
	}
	return (true);
}


static bool	is_date( const std::string& str ) {
	// if (str.length() != 11 || str[str.length() - 1] != ' ')
	if (str.length() != 10)
		return (false);
	for (int i = 0; i < 9; i++) {
		if (i == 4 || i == 7) {
			if (str[i] == '-')
				continue ;
			return (false);
		}
		if (std::isdigit(str[i]))
			continue ;
		return (false);
	}
	return (true);
}

static void	addRecord(std::map<Date, double>& map, std::string& line) {
	std::stringstream						s(line);
	std::string								rec;
	Date									date;
	double									price;
	std::map<Date, double>::const_iterator	cit;


	if (!std::getline(s, rec, ','))
		throw (BitcoinExchange::BadInputException());
	if (!is_date(rec))
		throw (BitcoinExchange::BadInputException());
	date = Date(rec);
	std::getline(s, rec);
	if (!is_number(rec))
		throw (BitcoinExchange::BadInputException());
	price = std::atof(rec.c_str());
	// if (!(s >> price))
	// 	throw (std::exception());
	cit = map.end();
	map[date] = price;
}

std::map<Date, double> BitcoinExchange::_init( const std::string& filename ) {
	std::ifstream			is;
	std::string				line;
	std::map<Date, double>	new_map;

	is.open(filename.c_str(), std::ios::in);
	if (!is.is_open())
		throw (BadFileException());
	std::getline(is, line);
	while (std::getline(is, line)) {
		addRecord(new_map, line);
	}
	return (new_map);
}

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
BitcoinExchange::BitcoinExchange( void ) : _database(std::map<Date, double>())
{
	this->_database = _init("./data.csv");
	return ;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & rhs )
	: _database(rhs.getDatabase())
{
	return ;
}

BitcoinExchange::BitcoinExchange( const std::string& filename )
{
	this->_database = _init(filename);
	return ;
}

BitcoinExchange::~BitcoinExchange( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
std::map<Date, double>	BitcoinExchange::getDatabase( void ) const {
	return (this->_database);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
BitcoinExchange& BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if (this != &rhs) {
		this->_database = rhs.getDatabase();
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
