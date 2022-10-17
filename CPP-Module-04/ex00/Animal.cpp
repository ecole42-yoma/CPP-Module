/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:48:36 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:01:22 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[Animal] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Animal::Animal(const std::string& type)
: type_(type)	{
	_PrintMsg("Default constructor called", type_);
}

Animal::~Animal()	{	_PrintMsg("Destructor called", type_);	}

Animal::Animal(const Animal& from)
: type_("Animal_Copy_Type")	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

Animal& Animal::operator=(const Animal& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	type_ = operand.getType();
	return *this;
}

void	Animal::makeSound(void) const	{	_PrintMsg("Let there be sound~", type_);	}

const std::string&	Animal::getType(void) const	{	return type_;	}
