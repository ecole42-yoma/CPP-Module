/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:07:56 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:18 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <curses.h>
#include <iostream>


namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[Form] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Form::Form(std::string const& name, int const& grade_sign, int const& grade_execute)
: name_(name), check_sign_(false), grade_sign_(grade_sign), grade_execute_(grade_execute) {
	_PrintMsg("Default constructor called", name_);
	if (grade_sign_ < kHighest)	{
		throw Form::GradeTooHighException();
	}
	else if (grade_sign_ > kLowest)	{
		throw Form::GradeTooLowException();
	}
	if (grade_execute_ < kHighest)	{
		throw Form::GradeTooHighException(false);
	}
	else if (grade_execute_ > kLowest)	{
		throw Form::GradeTooLowException(false);
	}
}

Form::~Form()	{	_PrintMsg("Destructor called", name_);	}

Form::Form(Form const& from)
: name_(from.name_), check_sign_(from.check_sign_), grade_sign_(from.grade_sign_), grade_execute_(from.grade_execute_) {
	_PrintMsg("Copy constructor called", name_);
}

Form& Form::operator=(const Form& operand)	{
	_PrintMsg("Copy assignment operator called", name_);
	if (this != &operand)	{
		const_cast<std::string&>(name_)		= operand.name_;
		check_sign_							= operand.check_sign_;
		const_cast<int&>(grade_sign_)		= operand.grade_sign_;
		const_cast<int&>(grade_execute_)	= operand.grade_execute_;
	}
	return *this;
}

std::string	Form::getName() const			{	return name_;	}
bool		Form::getSign() const			{	return check_sign_;	}
int			Form::getGradeSign() const		{	return grade_sign_;	}
int			Form::getGradeExecute() const	{	return grade_execute_;	}

void	Form::beSigned(Bureaucrat const& bur)	{
	if (bur.getGrade() > grade_sign_)	{
		throw Form::GradeTooLowException();
	}
	else {
		check_sign_ = true;
	}
}

void	Form::execute(Bureaucrat const& executor) const	{
	if (!check_sign_)	{
		throw std::string("\033[1;31mneed signed, before executing!\033[0m");
	}
	else if (executor.getGrade() > getGradeExecute())	{
		throw Form::GradeTooLowException(false);
	} else {
		workhorse();
	}
}

std::ostream& operator<<(std::ostream& __out, Form const& Form)	{
	return __out << Form.getName() << " : " << (Form.getSign() ? "[\033[1;32mSigned\033[0m]": "[\033[1;31mUnsigned\033[0m]") \
		<< ", required signed level is " << Form.getGradeSign() << ", required executed level is " << Form.getGradeExecute() << ".";
}

Form::GradeTooHighException::GradeTooHighException(bool excep_case) throw()
: case_(excep_case) {}

const char* Form::GradeTooHighException::what() const throw()	{
	if (case_)	{
		return "[\033[1;31mGrade [Sign] Too High ::\033[0m]";
	}
	else {
		return "[\033[1;31mGrade [Execute] Too High ::\033[0m]";
	}
}

Form::GradeTooLowException::GradeTooLowException(bool excep_case) throw()
: case_(excep_case) {}

const char* Form::GradeTooLowException::what() const throw()	{
	if (case_)	{
		return "[\033[1;31mGrade [Sign] Too Low ::\033[0m]";
	}
	else {
		return "[\033[1;31mGrade [Execute] Too Low ::\033[0m]";
	}
}
