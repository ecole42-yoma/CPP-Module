/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:48:36 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/15 00:00:37 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[AAnimal] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

AAnimal::AAnimal(const std::string& type)
: type_(type)	{
	_PrintMsg("Default constructor called", type_);
}

AAnimal::~AAnimal()	{	_PrintMsg("Destructor called", type_);	}

AAnimal::AAnimal(const AAnimal& from)
: type_("Animal_Copy_Type")	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

AAnimal& AAnimal::operator=(const AAnimal& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	type_ = operand.getType();
	return *this;
}

const std::string&	AAnimal::getType(void) const	{	return type_;	}
