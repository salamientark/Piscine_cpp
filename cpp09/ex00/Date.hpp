/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:01:10 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 09:34:02 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <ostream>
# include <iostream>
# include <string>
# include <cstdlib>
# include <sstream>

class Date {
public:
	Date( void );
	Date( Date const & rhs );
	Date( int year, int month, int day);
	Date( const std::string& date );
	~Date();

	Date& operator=( Date const & rhs );

	bool	operator==( const Date& rhs ) const;
	bool	operator!=( const Date& rhs ) const;
	bool	operator<( const Date& rhs ) const;
	bool	operator>( const Date& rhs ) const;
	bool	operator<=( const Date& rhs ) const;
	bool	operator>=( const Date& rhs ) const;

	int		getYear( void ) const;
	int		getMonth( void ) const;
	int		getDay( void ) const;

private:
	int	_year;
	int	_month;
	int	_day;
	
};

std::ostream&	operator<<( std::ostream& os, const Date& rhs );

#endif // !DATE_HPP
