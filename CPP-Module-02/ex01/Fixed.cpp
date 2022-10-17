/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:34:45 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/12 20:31:14 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::kFractionalBits_ = 8;

namespace	{
	void	_PrintMsg(const std::string& msg)	{
		std::cout << msg << std::endl;
	}

}

Fixed::Fixed(void) : fixed_point_value_(0)	{
	_PrintMsg("Default constructor called");
}

Fixed::~Fixed(void)	{
	_PrintMsg("Destructor called");
}

Fixed::Fixed(const int& value)	{
	_PrintMsg("Int constructor called");
	fixed_point_value_ = value << kFractionalBits_;
}

Fixed::Fixed(const float& value)	{
	_PrintMsg("Float constructor called");
	fixed_point_value_ = static_cast<int>(roundf(value * (1 << kFractionalBits_)));
}

Fixed::Fixed(const Fixed& from)	{
	_PrintMsg("Copy constructor called");
	*this = from;
}

Fixed& Fixed::operator=(const Fixed& operand)	{
	_PrintMsg("Copy assignment operator called");
	this->setRawBits(operand.getRawBits());
	return *this;
}

int	Fixed::getRawBits(void) const	{
	return fixed_point_value_;
}

void	Fixed::setRawBits(int const raw)	{
	fixed_point_value_ = raw;
}

float	Fixed::toFloat(void) const	{
	return static_cast<float>(fixed_point_value_) / (1 << kFractionalBits_);
}

int	Fixed::toInt(void) const	{
	return fixed_point_value_ >> kFractionalBits_;
}

std::ostream& operator<<(std::ostream& __out, const Fixed& fixed)	{
	return __out << fixed.toFloat();
}
