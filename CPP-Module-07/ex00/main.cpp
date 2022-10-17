/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:11:27 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/23 04:00:31 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "SMM.hpp"
#include <iostream>

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "c = " << c << std::endl;
	::swap(c, c);
	std::cout << "c = " << c << std::endl;
	std::cout << "\n-----------" << std::endl;
	{
		try	{
			const int a = 10;
			const int b = 42;

			std::cout << "a = " << a << ", b = " << b << std::endl;
			::swap( a, b );
			std::cout << "a = " << a << ", b = " << b << std::endl;
			std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
			std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		}	catch	(std::string const& e)	{
			std::cerr << e << std::endl;
		}

	}

	{
		std::cout << "\n-----------" << std::endl;
		const int a = 2;
		const int b = 3;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		const std::string c = "chaine1";
		const std::string d = "chaine2";

		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	}

	return 0;
}
