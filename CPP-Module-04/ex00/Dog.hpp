/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:01:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:02:18 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef __D_O_G__
# define __D_O_G__

# include "Animal.hpp"
# include <string>

class Dog : public Animal	{

	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &from);
		Dog& operator=(const Dog& from);

		virtual	void		makeSound() const;

};

#endif

