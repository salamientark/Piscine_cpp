/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:46:56 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 21:25:50 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>

template< typename T >
int	easyfind(T& container, int val) {
	typename T::iterator	it = std::find( container.begin(), container.end(), val);
	if (it == container.end())
		throw (std::exception());
	return (*it);
}

template< typename T >
int	easyfind(const T& container, int val) {
	typename T::const_iterator	it = std::find( container.begin(), container.end(), val);
	if (it == container.end())
		throw (std::exception());
	return (*it);
}

#endif // !EASYFIND_HPP
