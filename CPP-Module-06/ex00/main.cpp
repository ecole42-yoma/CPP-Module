/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:07:29 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/22 17:39:29 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])	{
	if (argc != 2)	{
		std:: cout << "./convert [ number or string ]" << std::endl;
		return 1;
	}
	else	{

		try {
			Conversion conv(argv[1]);

			conv.print("char");
			conv.print("int");
			conv.print("float");
			conv.print("double");

		} catch (std::string const& e) {
			std::cerr << e << std::endl;
		} catch (...)	{
			std::cerr << "[Error] some error occured" << std::endl;
		}

	}

	return 0;
}
