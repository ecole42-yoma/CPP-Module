/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:33:07 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/13 16:37:53 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void)	{

	Point	a(0, 0);
	Point	b(0, 3);
	Point	c(3, 0);

	std::cout << "[True case]" << std::endl;
	std::cout << "(1, 1)     : " << bsp(a, b, c, Point(1, 1)) << std::endl;
	std::cout << "(0.5, 2)   : " << bsp(a, b, c, Point(0.5, 2)) << std::endl;
	std::cout << "(2, 0.5)   : " << bsp(a, b, c, Point(2, 0.5)) << std::endl;
	std::cout << "(2, 0.5)   : " << bsp(a, b, c, Point(2, 0.5)) << std::endl;
	std::cout << "(1.5, 1.4) : " << bsp(a, b, c, Point(1.5, 1.4)) << std::endl;
	std::cout << "(1.5, 1.42) : " << bsp(a, b, c, Point(1.5, 1.42)) << std::endl;
	std::cout << "(1.5, 1.43) : " << bsp(a, b, c, Point(1.5, 1.43)) << std::endl;
	std::cout << "\n[False case]" << std::endl;
	std::cout << "(0, 0)     : " << bsp(a, b, c, Point(0, 0)) << std::endl;
	std::cout << "(0, 3)     : " << bsp(a, b, c, Point(0, 3)) << std::endl;
	std::cout << "(3, 0)     : " << bsp(a, b, c, Point(3, 0)) << std::endl;
	std::cout << "(1.5, 1.5) : " << bsp(a, b, c, Point(1.5, 1.5)) << std::endl;
	std::cout << "(1.75, 1.5): " << bsp(a, b, c, Point(1.7, 1.5)) << std::endl;
	std::cout << "(1.61, 1.39): " << bsp(a, b, c, Point(1.61, 1.39)) << std::endl;
	std::cout << "\n[Tolerance False case]" << std::endl;
	std::cout << "(1.5, 1.44) : " << bsp(a, b, c, Point(1.5, 1.44)) << std::endl;
	return 0;
}
