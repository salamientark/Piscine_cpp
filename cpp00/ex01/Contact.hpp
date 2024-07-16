/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:33:09 by madlab            #+#    #+#             */
/*   Updated: 2024/07/16 15:33:10 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>
#include <iomanip>

class Contact {
	public:
		std::string	f_name;	
		std::string	l_name;	
		std::string	n_name;	
		std::string	phone_nbr;
		std::string	dark_secret;

		Contact(void);
		Contact (std::string fn, std::string ln, std::string nn, std::string pn,
				std::string ds);
		~Contact(void);

		void	fill_contact( void );
		Contact	new_contact( void );

	private:

};

#endif
