/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:15:47 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/27 18:16:56 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <cstddef>
# include <stack>

template< typename T >
class MutantStack : public std::stack<T>{
public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack<T>( void );
	MutantStack<T>( MutantStack<T> const & rhs );
	~MutantStack<T>();

	MutantStack<T>& operator=( MutantStack<T> const & rhs );

	iterator				begin( void );
	const_iterator			begin( void ) const;
	iterator				end( void );
	const_iterator			end( void ) const;
	reverse_iterator		rbegin( void );
	reverse_iterator		rend( void );
	const_reverse_iterator	rbegin( void ) const;
	const_reverse_iterator	rend( void ) const;

private:
	
};

/* ************************************************************************** */
/*                            ITERATOR DEFINITION                             */
/* ************************************************************************** */
template< typename T >
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return (this->c.begin());
}

template< typename T >
typename MutantStack<T>::const_iterator	MutantStack<T>::begin( void ) const {
	return (this->c.begin());
}

template< typename T >
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin( void ) {
	return (this->c.rbegin());
}

template< typename T >
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin( void ) const {
	return (this->c.rbegin());
}

template< typename T >
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return (this->c.end());
}

template< typename T >
typename MutantStack<T>::const_iterator	MutantStack<T>::end( void ) const {
	return (this->c.end());
}

template< typename T >
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend( void ) {
	return (this->c.rend());
}

template< typename T >
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend( void ) const {
	return (this->c.rend());
}

/* ************************************************************************** */
/*                            ITERATOR DEFINITION                             */
/* ************************************************************************** */
template< typename T >
MutantStack<T>::MutantStack( void ) {}

template< typename T >
MutantStack<T>::MutantStack( MutantStack<T> const & rhs ) {
	MutantStack::operator=(rhs);
}

template< typename T >
MutantStack<T>::~MutantStack( void ) { }

template< typename T >
MutantStack<T>&	MutantStack<T>::operator=( MutantStack<T>  const & rhs ) {
	if (this != rhs)
		std::stack<T>::operator=(rhs);
	return (*this);
}

#endif // !MUTANTSTACK_HPP
