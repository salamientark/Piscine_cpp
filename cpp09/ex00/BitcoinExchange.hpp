/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:45:02 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 10:45:48 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <cctype>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include "Date.hpp"

class BitcoinExchange {
public:
	class BadFileException : public std::exception {
		public :
			virtual const char*	what() const throw();
	};
	class BadInputException : public std::exception {
		public :
			virtual const char	*what() const throw();
	};
	BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const & rhs );
	BitcoinExchange( const std::string& filename );
	~BitcoinExchange();

	BitcoinExchange& operator=( BitcoinExchange const & rhs );

	std::map<Date, double>	getDatabase( void ) const;

private:
	std::map<Date, double>	_database;

	std::map<Date, double>	_init( const std::string& filename );

};

#endif // !BITCOINEXCHANGE_HPP
