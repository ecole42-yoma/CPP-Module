/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:39:34 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 14:41:28 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <curses.h>
#include <iostream>
#include <fstream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[PresidentialPardonForm] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}

}

PresidentialPardonForm::PresidentialPardonForm(std::string const& name)
: Form(name, 25, 5) {
	_PrintMsg("Default constructor called", getName());

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& from)
:	Form(from.getName(), from.getGradeSign(), from.getGradeExecute())	{
	_PrintMsg("Copy constructor called", getName());

}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& operand)	{
	_PrintMsg("Copy assignment operator called", getName());
	if (this != &operand)	{
		Form::operator=(operand);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()	{	_PrintMsg("Destructor called", getName());	}

void	PresidentialPardonForm::workhorse() const	{
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
