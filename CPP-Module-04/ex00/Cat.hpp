/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:55:51 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 21:58:39 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef __C_A_T__
# define __C_A_T__

# include "Animal.hpp"
# include <string>

class Cat : public Animal	{

	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &from);
		Cat& operator=(const Cat& from);

		virtual	void		makeSound() const;

};

#endif
