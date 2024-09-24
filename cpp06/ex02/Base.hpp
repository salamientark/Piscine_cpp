/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:54:59 by dbaladro          #+#    #+#             */
/*   Updated: 2024/09/24 13:13:30 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public :
		virtual ~Base();

	private:
	
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate( void );
void	identify(Base *p);
void	identify(Base& p);

#endif // !BASE_HPP
