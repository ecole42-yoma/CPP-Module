/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:32:02 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/08 06:59:14 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "The memory address of the string variable : " << &string << std::endl;
	std::cout << "The memory address held by stringPTR      : " << stringPTR << std::endl;
	std::cout << "The memory address of the stringPTR       : " << &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF      : " << &stringREF << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "The value of the string variable          : " << string << std::endl;
	std::cout << "The value pointed to by stringPTR         : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         : " << stringREF << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "\tstringREF[2] = 'X'" << "\t// " << stringREF.length() << std::endl;
	stringREF[2] = 'X';
	stringREF[stringREF.length() - 1] = 'X';
	stringREF[stringREF.length()] = 'Y';
	stringREF[stringREF.length() + 1] = 'Z';
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "The value of the string variable          : " << string << std::endl;
	std::cout << "The value pointed to by stringPTR         : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         : " << stringREF << std::endl;
	return 0;
}
