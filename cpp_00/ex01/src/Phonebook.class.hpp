#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class Phonebook {
	private:
		int		_last_index;
		Contact	_book[8];	

		void	display( void ) const;
	public:
		Phonebook(void);
		~Phonebook(void);

		void	add_contact( void );
		void	search_contact( void ) const;
};

#endif
