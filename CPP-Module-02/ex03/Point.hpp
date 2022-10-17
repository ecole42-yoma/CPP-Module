/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:14:26 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 15:43:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class Point	{
	private:
		const Fixed	x_;
		const Fixed y_;

	public:
		Point(void);
		~Point(void);
		Point(const float x, const float y);
		Point(const Point& from);
		Point&	operator=(const Point& operand);

		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif /* __POINT_HPP__ */
