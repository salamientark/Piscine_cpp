/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:26:11 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 18:24:46 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
template< typename T>
class Array {
	public:
		Array<T>( void ) : _size(0), _content(new T[0]){ }
		Array<T>( unsigned int n ) : _size(n), _content(new T[n]){ };
		Array<T>( Array<T> const & rhs ) {
			unsigned int	size = rhs.size();

			this->_size = size;
			this->_content = new T[size];
			for (unsigned int i = 0; i < this->_size; i++){
				this->_content[i] = rhs[i];
			}
		};
		~Array<T>(){
			delete[](this->_content);
		};

		Array<T>& operator=( Array<T>& rhs ){
			if (this != &rhs) {
				delete[](this->_content);
				this->_size = rhs.size();
				this->_content = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++){
					this->_content[i] = rhs[i];
				}
			}
			return (*this);
		}

		T&			operator[](unsigned int index){
			if (index < 0 || index >= this->_size)
				throw (std::exception());
			return (this->_content[index]);
		}

		unsigned int	size( void ) const { return (this->_size); }

	private:
		unsigned int	_size;
		T*				_content;

};

#endif // !ARRAY_HPP
