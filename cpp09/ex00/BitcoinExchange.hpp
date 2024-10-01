/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:45:02 by dbaladro          #+#    #+#             */
/*   Updated: 2024/10/01 18:53:32 by dbaladro         ###   ########.fr       */
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
	class InitDBException : public std::exception {
		virtual const char* what() const throw();
	};
	class BadFileException : public std::exception {
		public :
			virtual const char*	what() const throw();
	};
	class BadInputException : public std::exception {
		public :
			virtual const char	*what() const throw();
	};
	class DateTooEarlyException : public std::exception {
		public :
			virtual const char*	what() const throw();
	};
	class TooLargeNbrException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
	class NegativeNbrException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
	class TryingToPredictFuturException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const & rhs );
	BitcoinExchange( const std::string& filename );
	~BitcoinExchange();

	BitcoinExchange&		operator=( BitcoinExchange const & rhs );

	std::map<Date, double>	getDatabase( void ) const;
	void					compare(const std::string& filename) const;

private:
	std::map<Date, double>	_database;

	std::map<Date, double>	_init( const std::string& filename );
	bool					_valid_date(const Date& date) const;

};

#endif // !BITCOINEXCHANGE_HPP
