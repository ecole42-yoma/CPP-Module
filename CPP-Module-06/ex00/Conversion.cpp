/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:58:06 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/22 17:52:02 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <limits>
#include <cmath>

Conversion::Conversion(char const* input)
:	input_(input), int_(0), double_(0), inf_nan_indicator_(false){
	{
		char const* temp_[kCapa] =	{
			"char",
			"int",
			"float",
			"double"
		};
		for (std::size_t i = 0; i < kCapa; ++i)	{
			func_name_[i] = temp_[i];
		}
	}
	{
		void	(Conversion::*fp_temp_[kCapa])() const =	{
			&Conversion::_charConv,
			&Conversion::_intConv,
			&Conversion::_floatConv,
			&Conversion::_doubleConv
		};
		for (std::size_t i = 0; i < kCapa; ++i)	{
			fp_[i] = fp_temp_[i];
		}
	}
	if (std::strlen(input_) == 1 && std::isprint(static_cast<int>(*input_)) && !std::isdigit(static_cast<int>(*input_)))	{
		int_	= static_cast<long>(*input_);
		double_	= static_cast<double>(*input_);
	}
	else	{
		char*	ptr_double_end	= NULL;
		char*	ptr_long_end	= NULL;

		double_	= std::strtod(input_, &ptr_double_end);
		int_	= std::strtol(input_, &ptr_long_end, 10);

		if (std::strlen(ptr_double_end) && (std::strcmp(ptr_double_end, "f") && std::strcmp(ptr_double_end, "F")))	{
			throw std::string("float surfix error");
		}
		if (std::isnan(double_) || std::isinf(double_))	{
			inf_nan_indicator_ = true;
			int_ = 0;
		}
	}
}

Conversion::~Conversion() {}

Conversion::Conversion(Conversion const& from)
:	input_(from.input_), int_(from.int_), double_(from.double_), inf_nan_indicator_(from.inf_nan_indicator_)	{
	for (std::size_t i = 0; i < kCapa; ++i)	{
		func_name_[i]	= from.func_name_[i];
		fp_[i]			= from.fp_[i];
	}
}

Conversion& Conversion::operator=(Conversion const& operand)	{
	if (this != &operand)	{
		input_				= operand.input_;
		int_				= operand.int_;
		double_				= operand.double_;
		inf_nan_indicator_	= operand.inf_nan_indicator_;
		for (std::size_t i = 0; i < kCapa; ++i)	{
			func_name_[i]	= operand.func_name_[i];
			fp_[i]			= operand.fp_[i];
		}
	}
	return *this;
}

void	Conversion::print(std::string const& type)	{
	for (std::size_t i = 0; i < kCapa; ++i)	{
		if (func_name_[i] == type)	{
			(this->*fp_[i])();
			return ;
		}
	}
	throw std::string("Invalid type");
}

void	Conversion::_charConv() const	{
	std::cout << "  char: ";
	if (inf_nan_indicator_)	{
        std::cout << "impossible";
	}
	else if (int_ < std::numeric_limits<char>::min() || int_ > std::numeric_limits<char>::max())	{
        std::cout << "impossible";
    }
	else {
		if (std::isprint(static_cast<char>(int_)))	{
			std::cout << "'" << static_cast<char>(int_) << "'";
		}
		else {
			std::cout << "Non displayable";
		}
	}
	std::cout << std::endl;
}

void	Conversion::_intConv() const	{
	std::cout << "   int: ";
	if (inf_nan_indicator_)	{
        std::cout << "impossible";
	}
	else if (int_ < std::numeric_limits<int>::min() || int_ > std::numeric_limits<int>::max())	{
        std::cout << "impossible";
    }
	else {
		std::cout << static_cast<int>(int_);
	}
	std::cout << std::endl;
}

void	Conversion::_floatConv() const	{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << " float: ";
	if (double_ > std::numeric_limits<float>::max())	{
		std::cout << std::showpos;
	}
	std::cout << static_cast<float>(double_) << "f" << std::endl;
}

void	Conversion::_doubleConv() const	{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: ";
	if (double_ > std::numeric_limits<double>::max())	{
		std::cout << std::showpos;
	}
	std::cout << double_ << std::endl;
}
