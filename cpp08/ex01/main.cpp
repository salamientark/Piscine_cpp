/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:28:37 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/25 01:04:09 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>


int	main( void )
{
	/*
	 * Default Test
	 */
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span	s(10);

	/*
	 * Testing with empty contaitiner
	 */
	std::cout << std::string(80, '*') << std::endl;
	std::cout << "Testing with empty Span" << std::endl;
	try {
		std::cout << "shortest_span is : " << s.shortestSpan() << std::endl;
		std::cout << "longest span is : " << s.longestSpan() << std::endl;
	} 
	catch (Span::SpanTooSmallException& e) {
		std::cerr << "Span::longestSpan : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	s.addNumber( 1 );
	try {
		std::cout << "shortest_span is : " << s.shortestSpan() << std::endl;
		std::cout << "longest span is : " << s.longestSpan() << std::endl;
	} 
	catch (Span::SpanTooSmallException& e) {
		std::cerr << "Span::longestSpan : " << e.what() << std::endl;
	}

	/*
	 * Testing with same value
	 */
	s = Span(10);
	std::cout << std::string(80, '*') << std::endl;
	std::cout << "Testing Same value in span" << std::endl;
	s.addNumber( 1 );
	s.addNumber( 1 );
	try {
		std::cout << "shortest_span is : " << s.shortestSpan() << std::endl;
		std::cout << "longest span is : " << s.longestSpan() << std::endl;
	} 
	catch (Span::SpanTooSmallException& e) {
		std::cerr << "Span::longestSpan : " << e.what() << std::endl;
	}
	s.addNumber( 13 );
	s.addNumber( 14 );
	s.addNumber( -1 );
	s.addNumber( 4 );
	s.addNumber( 13 );
	s.addNumber( -1 );
	try {
		std::cout << "shortest_span is : " << s.shortestSpan() << std::endl;
		std::cout << "longest span is : " << s.longestSpan() << std::endl;
	} 
	catch (Span::SpanTooSmallException& e) {
		std::cerr << "Span::longestSpan : " << e.what() << std::endl;
	}
	
	/*
	 * Big test 
	 */

	Span	big(10000);
	std::cout << std::string(80, '*') << std::endl;
	std::cout << "Testing with big value" << std::endl;
	try {
		big.fillSpan();
	}
	catch (std::exception& e)
	{
		std::cerr << "Span::fillSpan failed because : " << e.what() << std::endl;
	}
	try {
		std::cout << "shortest_span is : " << big.shortestSpan() << std::endl;
		std::cout << "longest span is : " << big.longestSpan() << std::endl;
	} 
	catch (Span::SpanTooSmallException& e) {
		std::cerr << "Span::longestSpan : " << e.what() << std::endl;
	}

	return (0);
}
