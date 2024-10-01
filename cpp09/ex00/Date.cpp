/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:53:50 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 18:52:27 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <iomanip>

/* ************************************************************************** */
/*                           Constructor and Destructors                      */
/* ************************************************************************** */
Date::Date( void ) : _year(1900), _month(1), _day(1)
{
	return ;
}

Date::Date( Date const & rhs )
	: _year(rhs.getYear()), _month(rhs.getMonth()), _day(rhs.getDay())
{
	return ;
}

Date::Date( int year, int month, int day )
	: _year(year), _month(month), _day(day)
{
	return ;
}

Date::Date( const std::string& str )
{
	std::stringstream	s(str);
	std::string			tmp;

	std::getline(s, tmp, '-');
	this->_year = std::atoi(tmp.c_str());
	std::getline(s, tmp, '-');
	this->_month = std::atoi(tmp.c_str());
	std::getline(s, tmp, ' ');
	this->_day = std::atoi(tmp.c_str());
}

Date::~Date( void )
{
	return ;
}

/* ************************************************************************** */
/*                                Getter And Setter                           */
/* ************************************************************************** */
int	Date::getYear( void ) const{
	return (this->_year);
}

int	Date::getMonth( void ) const{
	return (this->_month);
}

int	Date::getDay( void ) const{
	return (this->_day);
}

/* ************************************************************************** */
/*                                Operator Overload                           */
/* ************************************************************************** */
Date& Date::operator=( Date const & rhs )
{
	this->_year = rhs.getYear();
	this->_month = rhs.getMonth();
	this->_day = rhs.getDay();
	return (*this);
}

bool	Date::operator==( const Date& rhs ) const {
	return (this->getYear() == rhs.getYear()
			&& this->getMonth() == rhs.getMonth()
			&& this->getDay() == rhs.getDay());
}

bool	Date::operator!=( const Date& rhs ) const {
	return (!(*this == rhs));
}

bool	Date::operator<( const Date& rhs ) const {
	if (this->getYear() == rhs.getYear()) {
		if (this->getMonth() == rhs.getMonth())
			return (this->getDay() < rhs.getDay());
		return (this->getMonth() < rhs.getMonth());
	}
	return (this->getYear() < rhs.getYear());
}

bool	Date::operator>( const Date& rhs ) const {
	return (rhs < *this);
}

bool	Date::operator<=( const Date& rhs ) const {
	return (!(*this < rhs));
}

bool	Date::operator>=( const Date& rhs ) const {
	return (!(*this < rhs));
}

std::ostream&	operator<<( std::ostream& os, const Date& rhs)
{
	os << rhs.getYear() << "-"
		<< std::setw(2) << std::setfill('0') << rhs.getMonth() << "-"
		<< std::setw(2) << std::setfill('0') << rhs.getDay();
	return (os);
}

/* ************************************************************************** */
/*                             Public Member Function                         */
/* ************************************************************************** */
bool	Date::is_valid( void ) const {
	if (this->_year < 0)
		return (false);
	if (this->_month < 1 || this->_month > 12)
		return (false);
	if (this->_day < 1 || this->_day > 31)
		return (false);
	switch (this->_month) {
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 : 
		case 10 :
		case 12 :
			return (this->_day <= 31);
		case 4 :
		case 6 :
		case 9 :
		case 11 :
			return (this->_day <= 30);
		default :
			return ((this->_year % 100 == 0 && this->_year % 400 == 0)
					|| this->_year % 4 == 0);
	}
	return (true);
}

bool	Date::is_in_futur( void ) const {
	time_t	now = time(NULL);
	tm* date = std::localtime(&now);
	Date	today(date->tm_year + 1900, date->tm_mon + 1, date->tm_mday);
	
	return (*this > today);
}
