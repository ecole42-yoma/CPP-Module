/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:50:37 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 21:49:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[Bureaucrat] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Intern::Intern()	{
	_PrintMsg("Default constructor called", "Intern");
}

Intern::~Intern()	{	_PrintMsg("Destructor called", "Intern");	}

Intern::Intern(Intern const& from)	{
	_PrintMsg("Copy constructor called", "Intern");
	(void)from;
}

Intern& Intern::operator=(Intern const& operand)	{
	_PrintMsg("Copy assignment operator called", "Intern");
	(void)operand;
	return *this;
}

Form*	Intern::makeForm(std::string const& name, std::string const& target) const	{
	Form*	(Intern::*ft[3])(std::string const& name) const = {
		&Intern::pres,
		&Intern::robo,
		&Intern::shru
	};

	std::string		func_name[3] =	{
		"pres",
		"robo",
		"shru"
	};

	std::size_t		pos;

	for (pos = kPresidential; pos < kError; ++pos)	{
		if (name == func_name[pos])	{
			break ;
		}
	}

	if (static_cast<FormTable>(pos) < kError)	{
		return (this->*ft[pos])(target);
	}
	else {
		throw std::string("Not found any matched Function : " + name);
	}
}

Form*	Intern::pres(std::string const& target) const	{
	return new PresidentialPardonForm(target);
}

Form*	Intern::robo(std::string const& target) const	{
	return new  RobotomyRequestForm(target);
}

Form*	Intern::shru(std::string const& target) const	{
	return new ShrubberyCreationForm(target);
}
