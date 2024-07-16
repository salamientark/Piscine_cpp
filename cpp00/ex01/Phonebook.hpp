/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madlab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:32:38 by madlab            #+#    #+#             */
/*   Updated: 2024/07/16 15:37:18 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <sstream>

class Phonebook {
	private:
		int		_last_index;
		int		_size;
		Contact	_book[8];	

		void	display( void ) const;
		void	display_one_contact(int index) const;
	public:
		Phonebook(void);
		~Phonebook(void);

		void	add_contact( void );
		void	search_contact( void ) const;
};

#endif
