/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:33:29 by madlab            #+#    #+#             */
/*   Updated: 2024/07/17 23:36:18 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Harl.hpp"

int	main( void )
{
	Harl	karen;

	karen.complain("");
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	karen.complain("Nooooooooooo");
	return (0);
}
