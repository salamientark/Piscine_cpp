/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:34:49 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 19:01:40 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <climits>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

const char*	BitcoinExchange::InitDBException::what() const throw() {
	return ("couldn't open database file");
}

const char*	BitcoinExchange::BadInputException::what() const throw() {
	return ("bad input");
}

const char*	BitcoinExchange::BadFileException::what() const throw() {
	return ("could not open file");
}

const char*	BitcoinExchange::DateTooEarlyException::what() const throw() {
	return ("trying to check a date before database beginning");
}

const char* BitcoinExchange::TooLargeNbrException::what() const throw() {
	return ("too large a number.");
}

const char* BitcoinExchange::NegativeNbrException::what() const throw() {
	return ("not a positive number.");
}

const char* BitcoinExchange::TryingToPredictFuturException::what() const throw() {
	return ("cannot predict future.");
}


static bool	is_number(const std::string& str) {
	bool					decimal = false;
	std::string::const_iterator	it = str.begin();

	if (*it == '-')
		it++;
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
	cit = map.end();
	map[date] = price;
}

std::map<Date, double> BitcoinExchange::_init( const std::string& filename ) {
	std::ifstream			is;
	std::string				line;
	std::map<Date, double>	new_map;

	is.open(filename.c_str(), std::ios::in);
	if (!is.is_open())
		throw (InitDBException());
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
static void	get_bitcoin_value(const std::map<Date, double>& map, const Date& date, double btc) {
	std::map<Date, double>::const_iterator	it = map.begin();
	Date									last_date = it->first;

	for (it = map.begin(); it != map.end(); it++) {
		if (it->first > date)
			break ;
		last_date = it->first;
	}
	std::cout << date << " => " << btc << " = " << map.find(last_date)->second * btc << std::endl;
}

static void	readline(const std::string& line, const std::map<Date, double>& map) {
	std::stringstream	s(line);
	std::string			split;
	Date				date;

	if (!std::getline(s, split, ' '))
		throw (BitcoinExchange::BadInputException());
	if (!is_date(split))
		throw (BitcoinExchange::BadInputException());
	date = Date(split);
	if (!date.is_valid())
		throw (BitcoinExchange::BadInputException());
	if (map.begin()->first > date)
		throw (BitcoinExchange::DateTooEarlyException());
	if (date.is_in_futur())
		throw (BitcoinExchange::TryingToPredictFuturException());
	if (!std::getline(s, split, ' '))
		throw (BitcoinExchange::BadInputException());
	if (!std::getline(s, split))
		throw (BitcoinExchange::BadInputException());

	std::stringstream	ss(split);
	double price;
	if (!(ss >> price) || price > INT_MAX)
		throw (BitcoinExchange::TooLargeNbrException());
	if (price < 0)
		throw (BitcoinExchange::NegativeNbrException());
	char c;
	if (ss >> c)
			throw (BitcoinExchange::BadInputException());
	get_bitcoin_value(map, date, price);
}

void	BitcoinExchange::compare(const std::string& filename) const {
	std::ifstream	ifs;
	std::string		line;
	bool			first = true;

	if (ifs.open(filename.c_str(), std::ios::in), !ifs.is_open())
		throw (BadFileException());
	while (getline(ifs, line)) {
		if (line.length() == 0)
			continue ;
		if (first == true && line.compare("date | value") == 0) {
			first = false;
			continue ;
		}
		try {
			readline(line, this->_database);
		}
		catch (BitcoinExchange::BadInputException& e) {
			std::cerr << "Error: " << e.what() << " => " << line << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
