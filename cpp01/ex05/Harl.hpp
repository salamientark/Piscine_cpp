/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:17:14 by madlab            #+#    #+#             */
/*   Updated: 2024/07/18 00:01:04 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>


class Harl {
public:
	Harl( void );
	~Harl( void );

	typedef void(Harl::*HarlFctPtr)( void ); 

	void	complain( std::string level );

private:
	std::pair<std::string, HarlFctPtr>	fct_lst[4];

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};


#endif
