/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:02:59 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/20 18:37:10 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
class Brain {
	public:
		Brain( void );
		Brain( Brain const & rhs );
		~Brain();

		Brain& operator=( Brain const & rhs );

		const std::string*	getIdeas( void ) const;

	private:
		std::string	ideas[100];
		
};

#endif // !BRAIN_HPP
