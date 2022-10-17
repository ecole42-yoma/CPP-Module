/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:02:45 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:11:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[Dog] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Dog::Dog()
: Animal("Dog")	{
	_PrintMsg("Default constructor called", type_);
}

Dog::~Dog()	{	_PrintMsg("Destructor called", type_);	}

Dog::Dog(const Dog& from)
: Animal("Dog_Copy_Type")	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

Dog& Dog::operator=(const Dog& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	Animal::operator=(operand);
	return *this;
}

void	Dog::makeSound(void) const	{	_PrintMsg("Bark!", type_);	}
