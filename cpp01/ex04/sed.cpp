/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:23:48 by madlab            #+#    #+#             */
/*   Updated: 2024/07/17 15:36:13 by madlab           ###   ########.fr       */
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
	std::size_t				pos = 0;
	std::size_t				offset = 0;
	const std::size_t		len = input.length();
	const std::size_t		s2_len = s2.length();

	while (pos < len)
	{
		offset = input.find(s1, pos);
		if (offset == input.npos)
		{
			output.write(&input[pos], len - pos);
			break ;
		}
		output.write(&input[pos], offset - pos);
		output.write(s2.c_str(), s2_len);
		pos = offset + s1.length();
	}
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
