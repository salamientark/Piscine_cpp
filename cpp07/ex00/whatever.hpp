/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:37:19 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 16:46:27 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void	swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template< typename T >
const T&	min(const T&a, const T& b)
{
	if (a >= b)
		return (b);
	return (a);
}

template< typename T >
const T&	max(const T&a, const T& b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif // !WHATEVER_HPP
