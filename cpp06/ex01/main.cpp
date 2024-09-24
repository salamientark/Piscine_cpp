/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:09 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 12:51:53 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <ios>
#include <string>
#include <iostream>

int	main( void )
{
	Data		data;
	Data*		data_ptr;
	uintptr_t	raw_ptr = 0;
	Data*		new_data_ptr = NULL;

	data.a = 1;
	data.b = 'b';
	data_ptr = &data;

	std::cout << std::string(80, '*') << std::endl
		<< "Init value :" << std::endl
		<< "data.a " << data.a << std::endl << "data.b : " << data.b << std::endl
		<< "data addr    : " << std::hex << &data << std::endl
		<< "data_ptr     : " << std::hex << data_ptr << std::endl
		<< "raw_ptr      : " << std::hex << raw_ptr << std::endl
		<< "new_data_ptr : " << std::hex << new_data_ptr << std::endl
		<< std::endl;

	std::cout << "===> Serializing <===" << std::endl;
	raw_ptr = Serializer::serialize(data_ptr);
	std::cout 
		<< "data addr    : " << std::hex << &data << std::endl
		<< "data_ptr     : " << std::hex << data_ptr << std::endl
		<< "raw_ptr      : " << std::showbase << std::hex << raw_ptr << std::endl
		<< "new_data_ptr : " << std::hex << new_data_ptr << std::endl
		<< std::endl;

	std::cout << "===> Deserializing <===" << std::endl;
	new_data_ptr = Serializer::deserialize(raw_ptr);
	std::cout 
		<< "data addr    : " << std::hex << &data << std::endl
		<< "data_ptr     : " << std::hex << data_ptr << std::endl
		<< "raw_ptr      : " << std::hex << raw_ptr << std::endl
		<< "new_data_ptr : " << std::hex << new_data_ptr << std::endl
		<< std::endl;

	return (0);
}
