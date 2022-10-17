/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:50:48 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 17:18:20 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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

Bureaucrat::Bureaucrat(std::string const& name, int const& grade)
: name_(name), grade_(grade) {
	_PrintMsg("Default constructor called", name_);
	if (grade_ < kHighest)	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade_ > kLowest)	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat()	{	_PrintMsg("Destructor called", name_);	}

Bureaucrat::Bureaucrat(const Bureaucrat& from)	{
	_PrintMsg("Copy constructor called", name_);
	*this = from;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& operand)	{
	_PrintMsg("Copy assignment operator called", name_);
	if (this != &operand)	{
		const_cast<std::string&>(name_) = operand.name_;
		grade_ = operand.grade_;
	}
	return *this;
}

std::string	Bureaucrat::getName() const	{ return name_;	}
int	Bureaucrat::getGrade() const	{	return grade_;	}

void	Bureaucrat::levelUp() const	{
	if (grade_ - 1 < kHighest)	{
			throw Bureaucrat::GradeTooHighException();
	}
	else	{
		_PrintMsg("I got +1 ", name_);
		--grade_;
	}
}

void	Bureaucrat::levelDown() const	{
	if (grade_ + 1 > kLowest)	{
			throw Bureaucrat::GradeTooLowException();
	}
	else	{
		_PrintMsg("I got -1 ", name_);
		++grade_;
	}
}

void	Bureaucrat::signForm(Form& form) const	{
	try {
		form.beSigned(*this);
		std::cout << "\033[1;32m" <<  name_ << " signed " << form.getName() << "\033[0m" << std::endl;

	} catch (std::exception const& e) {
		std::cout << name_ << " couldn't sign " << form.getName() << " because \033[1;31m" << e.what() << "\033[0m" << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const& form) const	{
	try {
		form.execute(*this);
		std::cout << "\033[1;32m" << name_ << " executed "<< form.getName() << "\033[0m" << std::endl;
	} catch (std::exception const& e) {
		std::cerr << name_ << " couldn't executed " << form.getName() << " because \033[1;31m" << e.what() << "\033[0m" << std::endl;
	} catch (std::string const& e)	{
		std::cerr << name_ << " couldn't executed " << form.getName() << " because \033[1;31m" << e << "\033[0m" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& __out, Bureaucrat const& bureaucat)	{
	return __out << bureaucat.getName() << ", bureaucrat grade " << bureaucat.getGrade() << ".";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()	{
	return "bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()	{
	return "bureaucrat grade too low";
}
