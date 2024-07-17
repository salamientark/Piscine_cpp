/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:23:48 by madlab            #+#    #+#             */
/*   Updated: 2024/07/17 18:13:12 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

/*
 * Copy from <ifs> to <ofs> replacing every occurence of <s1> with <s2>
 * */
int	copy_and_replace(std::ifstream & ifs, std::ofstream & output,
		const std::string s1, const std::string s2)
{
	std::string				input((std::istreambuf_iterator<char>(ifs)),
									std::istreambuf_iterator<char>());
	std::string				buffer;
	std::size_t				pos = 0;
	std::size_t				offset = 0;
	const std::size_t		s1_len = s1.length();

	while ((offset = input.find(s1, pos)) != input.npos)
	{
		buffer = input.substr(offset + s1_len);
		input.erase(offset, input.npos);
		input += s2 + buffer;
		pos = offset;
	}
	output << input;
	return (0);
}

/*
 * Open necessary file checking for errors then perform the sed operration
 * Return :
 *	- 0 on success
 *	- Everything elese mean ERROR
 * */
int	sed( const char *filename, const std::string s1, const std::string s2 )
{
	std::ifstream	ifs;
	std::ofstream	ofs;

	ifs.open(filename, std::ios::in);
	if (!ifs.is_open())
	{
		std::cerr << "ifstream.open(): " << filename << ": " << std::strerror(errno) << std::endl;
		return (errno);
	}
	ofs.open((std::string(filename) + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!ofs.is_open())
	{
		ifs.close();
		std::cerr << "ofstream.open(): " << filename << ": " << std::strerror(errno) << std::endl;
		return (errno);
	}
	return (copy_and_replace(ifs, ofs, s1, s2));
}
