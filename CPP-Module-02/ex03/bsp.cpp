/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:28:03 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/13 16:17:31 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

namespace  {
	Fixed	_getTriArea(Point const& p1, Point const& p2, Point const& p3)	{
		Fixed	area = ((p1.getX() * (p2.getY() - p3.getY()))
						+ (p2.getX() * (p3.getY() - p1.getY()))
						+ (p3.getX() * (p1.getY() - p2.getY())))
						/ Fixed(static_cast<float>(2.0));

		Fixed	zero(0);
		if (area < zero)	{
			area = zero - area;
		}
		return area;
	}
}

bool bsp(Point const a, Point const b, Point const c, Point const point)	{
	Fixed	abc = _getTriArea(a, b, c);
	Fixed	pbc = _getTriArea(point, b, c);
	Fixed	apc = _getTriArea(a, point, c);
	Fixed	abp = _getTriArea(a, b, point);
	Fixed	zero(0);

	if (pbc == zero || apc == zero || abp == zero)
		return false;
	return abc == pbc + apc + abp;
}
