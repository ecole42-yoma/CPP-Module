/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:59:50 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 14:26:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include <curses.h>
#include <iostream>
#include <fstream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[RobotomyRequestForm] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}

}

RobotomyRequestForm::RobotomyRequestForm(std::string const& name)
: Form(name, 72, 45) {
	_PrintMsg("Default constructor called", getName());

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& from)
:	Form(from.getName(), from.getGradeSign(), from.getGradeExecute())	{
	_PrintMsg("Copy constructor called", getName());

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& operand)	{
	_PrintMsg("Copy assignment operator called", getName());
	if (this != &operand)	{
		Form::operator=(operand);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()	{	_PrintMsg("Destructor called", getName());	}

void	RobotomyRequestForm::workhorse() const	{
	_PrintMsg("\033[1;32mDriliiiiiiiiiiiinnnnngggg......\033[0m", getName());

	char	byte;
	std::ifstream("/dev/urandom").get(byte);
	if (byte & 1)	{
		std::cout << "\033[1;32m" << getName() << " has been robotomized!\033[0m" << std::endl;
	}
	else	{
		std::cout << "\033[1;31m" << getName() << " has been failed to robotomized..\033[0m" << std::endl;
	}
}
