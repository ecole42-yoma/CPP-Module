/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:22:13 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 18:02:00 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[\033[1;31mAMateria\033[0m] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

AMateria::AMateria(std::string const& type)
: type_(type)	{
	_PrintMsg("Default constructor called", type_);
}

AMateria::AMateria(AMateria const& from)
: type_(from.type_){
	_PrintMsg("Copy constructor called", type_);
	// *this = from;
}

AMateria&	AMateria::operator=(AMateria const& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	(void)operand;
	// type_ = operand.getType();
	return *this;
}

AMateria::~AMateria()	{	_PrintMsg("Destructor called", type_);	}

const std::string&	AMateria::getType() const	{	return type_;	}

void	AMateria::use(ICharacter& target)	{	(void)target;	}
