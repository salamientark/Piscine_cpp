/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:26:52 by madlab            #+#    #+#             */
/*   Updated: 2024/07/26 11:03:04 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <utility>

# define DEFAULT_MSG "[ Yeah Yeah Yeah ... ! ]"
# define DEBUG_MSG "[ DEBUG ]\nplease don't use a standard debuf message for debugging"
# define INFO_MSG "[ INFO ]\nThis message is very informative"
# define WARNING_MSG "[ WARNING ]\nBe carreful !"
# define ERROR_MSG "[ ERROR ]\nWHAT HAVE YOU DONE !!!"


class Harl
{
	typedef void (Harl::*Harlmfp)( void ) const;
	
	public:
		Harl( void );
		~Harl( void );

		void	complain( std::string level ) const;

	private:
		std::pair<int, std::string> _level[4];
		int		getLevelValue( const std::string level ) const;

		void	debug( void ) const;
		void	info( void ) const;
		void	warning( void ) const;
		void	error( void ) const;
};

#endif
