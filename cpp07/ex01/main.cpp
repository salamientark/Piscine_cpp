/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:58:52 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 18:21:08 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main( void )
{
	int			int_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
	char		char_array[6] = {'H', 'e', 'l', 'l', 'o', '!'};
	std::string	str_array[3] = {"aaa", "zzz", "ccc"};


	/*
	 * INT ARRAY
	 */
	std::cout << std::string(80, '*') << std::endl
		<< "===> int_array <===" << std::endl
		<< "array adress : " << std::hex << &int_array << std::endl
		<< "array len    : " << std::dec << 10 << std::endl;
	::iter<int>(int_array, 10, ::print<int>);

	/*
	 * CHAR ARRAY
	 */
	std::cout << std::string(80, '*') << std::endl
		<< "===> char_array <===" << std::endl
		<< "array adress : " << std::hex << &char_array << std::endl
		<< "array len    : " << std::dec << 6 << std::endl;
	iter<char>(char_array, 6, ::print<char>);

	/*
	 * STRING ARRAY
	 */
	std::cout << std::string(80, '*') << std::endl
		<< "===> str_array <===" << std::endl
		<< "array adress : " << std::hex << &str_array << std::endl
		<< "array len    : " << std::dec << 3 << std::endl;
	::iter<std::string>(str_array, 3, ::print<std::string>);

	std::cout << std::string(80, '*') << std::endl
		<< "===> char_array after add_ont <===" << std::endl
		<< "array adress : " << std::hex << &str_array << std::endl
		<< "array len    : " << std::dec << 3 << std::endl;
	::iter<char>(char_array, 6, ::add_one<char>);
	::iter<char>(char_array, 6, ::print<char>);
	
	return (0);
}
