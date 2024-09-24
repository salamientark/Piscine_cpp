/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:25:51 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 12:47:00 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"


class Serializer {
public:
	static	uintptr_t	serialize( Data* ptr );
	static	Data*		deserialize( uintptr_t raw );

private:
	Serializer( void );
	Serializer( Serializer const & rhs );
	~Serializer();

	Serializer& operator=( Serializer const & rhs );
	
};

#endif // !SERIALIZER_HPP
