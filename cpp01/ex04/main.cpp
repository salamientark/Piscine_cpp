/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:23:48 by madlab            #+#    #+#             */
/*   Updated: 2024/10/07 16:31:31 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include <iostream>

/*
 * ft_sed take a filename and two string as paramaters.
 * It will open the file <filename> * and copy it content
 * in a new file <filename>.replace, replacing every occurance of <s1> by <s2>.
 * Return :
 *	- 0 on Success
 *	- 1 on error
 * */
int	main(int ac, char* av[])
{
	if (ac != 4)
	{
		std::cerr << "Please use ft_sed in this way:\n$> ./ft_sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	return (sed(av[1], av[2], av[3]));
}
