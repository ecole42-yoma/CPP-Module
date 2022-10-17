/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:59:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:12:05 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[Cat] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Cat::Cat()
: Animal("Cat")	{
	_PrintMsg("Default constructor called", type_);
}

Cat::~Cat()	{	_PrintMsg("Destructor called", type_);	}

Cat::Cat(const Cat& from)
: Animal("Cat_Copy_Type")	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

Cat& Cat::operator=(const Cat& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	Animal::operator=(operand);
	return *this;
}

void	Cat::makeSound(void) const	{	_PrintMsg("Meow~", type_);	}

