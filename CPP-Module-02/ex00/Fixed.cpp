/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:58:10 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/12 20:30:10 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


const int Fixed::kFractionalBits_ = 8;

Fixed::Fixed(void) : fixed_point_value_(0)	{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)	{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& from)	{
	std::cout << "Copy constructor called" << std::endl;
	*this = from;
}

Fixed& Fixed::operator=(const Fixed& operand)	{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(operand.getRawBits());
	return *this;
}

int	Fixed::getRawBits(void) const	{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point_value_;
}

void	Fixed::setRawBits(int const raw)	{
	fixed_point_value_ = raw;
}
