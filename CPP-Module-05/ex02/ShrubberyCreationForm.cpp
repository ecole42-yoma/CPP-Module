/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:51:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 14:02:20 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <curses.h>
#include <iostream>
#include <fstream>

# define ASCII_TREE	                          \
    "                     .o00o\n"            \
    "                   o000000oo\n"          \
    "                  00000000000o\n"        \
    "                 00000000000000\n"       \
    "              oooooo  00000000  o88o\n"  \
    "           ooOOOOOOOoo  ```''  888888\n" \
    "         OOOOOOOOOOOO'.qQQQQq. `8888'\n" \
    "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"  \
    "        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"    \
    "         OOOOOOOOO QQQQQQQQQQ/ /QQ\n"    \
    "           OOOOOOOOO `QQQQQQ/ /QQ'\n"    \
    "             OO:F_P:O `QQQ/  /Q'\n"      \
    "                \\\\. \\ |  // |\n"      \
    "                d\\ \\\\\\|_////\n"      \
    "                qP| \\ _' `|Ob\n"        \
    "                   \\  / \\  \\Op\n"     \
    "                   |  | O| |\n"          \
    "           _       /\\. \\_/ /\\\n"      \
    "            `---__/|_\\\\   //|  __\n"   \
    "                  `-'  `-'`-'-'\n"

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[ShrubberyCreationForm] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}

	std::string	_asciiTree()	{
		return ASCII_TREE;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& name)
: Form(name, 145, 137) {
	_PrintMsg("Default constructor called", getName());

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& from)
:	Form(from.getName(), from.getGradeSign(), from.getGradeExecute())	{
	_PrintMsg("Copy constructor called", getName());

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& operand)	{
	_PrintMsg("Copy assignment operator called", getName());
	if (this != &operand)	{
		Form::operator=(operand);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()	{	_PrintMsg("Destructor called", getName());	}

void	ShrubberyCreationForm::workhorse() const	{
	std::fstream	fs;
	std::string		file_name = Form::getName() + "_shrubbery";

	fs.open(file_name, std::fstream::out | std::fstream::trunc);
	if (!fs)	{
		throw	std::string("Can't open file : " + file_name);
	}
	fs << _asciiTree();
	if (fs.is_open())	{
		_PrintMsg("\033[1;32m[OK] Ascii Art in " + file_name, getName() + "\033[0m");
		fs.close();
	}
}
