/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:06:34 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:07:43 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[WrongAnimal] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

WrongAnimal::WrongAnimal(const std::string& type)
: type_(type)	{
	_PrintMsg("Default constructor called", type_);
}

WrongAnimal::~WrongAnimal()	{	_PrintMsg("Destructor called", type_);	}

WrongAnimal::WrongAnimal(const WrongAnimal& from)
: type_("Animal_Copy_Type")	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	type_ = operand.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const	{	_PrintMsg("Let there be wrong sound~", type_);	}

const std::string&	WrongAnimal::getType(void) const	{	return type_;	}
