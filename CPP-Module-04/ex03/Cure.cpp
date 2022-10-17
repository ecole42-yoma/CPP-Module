/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:44:32 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 18:04:55 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[\033[1;32mCure\033[0m] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Cure::Cure(std::string const& type)
: AMateria(type)	{
	_PrintMsg("Default constructor called", type_);
}

Cure::Cure(Cure const& from)
: AMateria(from)	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

Cure&	Cure::operator=(Cure const& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	AMateria::operator=(operand);
	return *this;
}

Cure::~Cure()	{	_PrintMsg("Destructor called", type_);	}

AMateria*	Cure::clone() const	{	return new Cure(*this);	}

void	Cure::use(ICharacter& target)	{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
