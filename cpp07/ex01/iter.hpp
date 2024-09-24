/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:48:04 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 17:17:29 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <stdlib.h>
# include <iostream>

template< typename T >
void	iter(T (*addr)[], size_t len, void (*f)(const T&))
{
	for (size_t i = 0; i < len; i++) {
		f((*addr)[i]);
	}
	return ;
}

template< typename T >
void	print(const T& var)
{
	std::cout << var << std::endl;
	return ;
}

#endif // !ITER_HPP
