/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:28:42 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/25 00:55:03 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span {
public:
	class SpanTooSmallException : public std::exception {
		public :
			const char*	what() const throw();
	};
	class SpanMaxSizeReachedException : public std::exception {
		public :
			const char*	what() const throw();
	};

	Span( void );
	Span( const unsigned int max_size );
	Span( Span const & rhs );
	~Span();

	Span&				operator=( Span const & rhs );

	unsigned int		getMaxSize( void ) const;
	std::vector<int>	getV( void ) const;

	void	addNumber( int nbr );
	void	fillSpan( void );
	int		shortestSpan( void ) const;
	int		longestSpan( void ) const;

private:
	unsigned int		_max_size;
	std::vector<int>	_v;
	
};

#endif // !SPAN_HPP
