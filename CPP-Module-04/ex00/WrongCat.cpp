/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:08:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:11:21 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[WrongCat] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

WrongCat::WrongCat()
: WrongAnimal("WrongCat")	{
	_PrintMsg("Default constructor called", type_);
}

WrongCat::~WrongCat()	{	_PrintMsg("Destructor called", type_);	}

WrongCat::WrongCat(const WrongCat& from)
: WrongAnimal("WrongCat_Copy_Type")	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

WrongCat& WrongCat::operator=(const WrongCat& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	WrongAnimal::operator=(operand);
	return *this;
}

void	WrongCat::makeSound(void) const	{	_PrintMsg("Meow~", type_);	}
