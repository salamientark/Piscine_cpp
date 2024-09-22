/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:16:54 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/22 08:06:45 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	Bureaucrat	bob;
	Bureaucrat	josey = Bureaucrat("josey", 0);
	Bureaucrat	loli = Bureaucrat("loli", 151);
	Bureaucrat	gg = Bureaucrat("gg", 5);

	std::cout << bob << std::endl;
	std::cout << josey << std::endl;
	std::cout << loli << std::endl;
	std::cout << gg << std::endl;


	loli.decrementGrade();
	std::cout << loli << std::endl;
	loli.decrementGrade();
	std::cout << loli << std::endl;
	loli.incrementGrade();
	std::cout << loli << std::endl;

	gg.incrementGrade();
	std::cout << gg << std::endl;
	gg.incrementGrade();
	std::cout << gg << std::endl;
	gg.incrementGrade();
	std::cout << gg << std::endl;
	gg.incrementGrade();
	std::cout << gg << std::endl;
	gg.incrementGrade();
	std::cout << gg << std::endl;
	gg.incrementGrade();
	std::cout << gg << std::endl;
	gg.incrementGrade();
	std::cout << gg << std::endl;

	return (0);
}
