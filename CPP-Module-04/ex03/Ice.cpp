/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:17:37 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 18:07:05 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[\033[1;35mIce\033[0m] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Ice::Ice(std::string const& type)
: AMateria(type)	{
	_PrintMsg("Default constructor called", type_);
}

Ice::Ice(Ice const& from)
: AMateria(from)	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

Ice&	Ice::operator=(Ice const& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	AMateria::operator=(operand);
	return *this;
}

Ice::~Ice()	{	_PrintMsg("Destructor called", type_);	}

AMateria*	Ice::clone() const	{	return new Ice(*this);	}

void	Ice::use(ICharacter& target)	{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
