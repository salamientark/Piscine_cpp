/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:48:04 by dbaladro          #+#    #+#             */
/*   Updated: 2024/12/20 18:17:41 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <stdlib.h>
# include <iostream>

template< typename T , typename F >
void	iter(T* addr, size_t len, F func)
{
	if (!addr || !func)
		return ;
	for (size_t i = 0; i < len; i++) {
		func(addr[i]);
	}
	return ;
}

template< typename T >
void	print(const T& var)
{
	std::cout << var << std::endl;
	return ;
}

template< typename T >
void add_one(T& var)
{
	var += 1;
	return ;
}

#endif // !ITER_HPP
