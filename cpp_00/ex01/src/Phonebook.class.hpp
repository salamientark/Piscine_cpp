#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

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
