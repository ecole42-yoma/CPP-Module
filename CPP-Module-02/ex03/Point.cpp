/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:17:39 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:01 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

namespace	{
	void	_PrintMsg(const std::string& msg)	{
		#ifdef LOG
			std::cout << "[Point] " << msg << std::endl;
		#else
			(void)msg;
		#endif
	}
}

Point::Point(void): x_(0), y_(0)	{
	_PrintMsg("Default constructor called");
}

Point::~Point(void)	{
	_PrintMsg("Destructor called");
}

Point::Point(const float x, const float y): x_(x), y_(y)	{
	_PrintMsg("Float Constructor called");
}

Point::Point(const Point& from){
	_PrintMsg("Copy constructor called");
	*this = from;
}

Point&	Point::operator=(const Point& operand)	{
	_PrintMsg("Copy assignment operator called");
	const_cast<Fixed&>(this->x_) = operand.x_;
	const_cast<Fixed&>(this->y_) = operand.y_;
	return (*this);
}

const Fixed&	Point::getX(void) const	{
	return (this->x_);
}

const Fixed&	Point::getY(void) const	{
	return (this->y_);
}
