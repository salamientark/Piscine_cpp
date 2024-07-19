/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:26:52 by madlab            #+#    #+#             */
/*   Updated: 2024/07/20 00:00:12 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
#include <utility>

class Harl
{
	typedef void (Harl::*Harlmfp)( void ) const;
	
	public:
		Harl( void );
		~Harl( void );

		void	complain( std::string level ) const;

	private:
		std::pair<std::string, Harlmfp>	msg_l[4]; 

		void	debug( void ) const;
		void	info( void ) const;
		void	warning( void ) const;
		void	error( void ) const;
};

#endif
