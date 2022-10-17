/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:16:53 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/22 17:22:01 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

namespace {

	std::string	_colorPrint(std::string const& str, int key)	{
		if (key == 1)	{
			return std::string("\033[1;32m" + str + "\033[0m");
		}
		else if (key == 2)	{
			return std::string("\033[1;33m" + str + "\033[0m");
		}
		else{
			return std::string("\033[1;35m" + str + "\033[0m");
		}
	}

	Base*	generate(void)	{
		switch	(std::rand() % 3)	{
			case 0:
				std::cout << _colorPrint("[A]", 1) << "is created" << std::endl;
				return new A;

			case 1:
				std::cout << _colorPrint("[B]", 2) << "is created" << std::endl;
				return new B;

			case 2:
				std::cout << _colorPrint("[C]", 3) << "is created" << std::endl;
				return new C;

			default:
				throw std::exception();
		}
		return NULL;
	}

	void	identify(Base* p)	{
		if (dynamic_cast<A*>(p))
			std::cout << _colorPrint("A", 1) << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << _colorPrint("B", 2) << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << _colorPrint("C", 3) << std::endl;
		else
			throw std::exception();
	}

	void	identify(Base& p)	{
		try	{
			(void)dynamic_cast<A&>(p);
			std::cout << _colorPrint("A", 1) << std::endl;
		} catch	(...)	{
			try {
				(void)dynamic_cast<B&>(p);
				std::cout << _colorPrint("B", 2) << std::endl;
			} catch (...)	{
				try {
					(void)dynamic_cast<C&>(p);
					std::cout << _colorPrint("C", 3) << std::endl;
				}
				catch(...) {
					throw std::exception();
				}
			}
		}
	}
}

int main()	{
	bool		on = true;
	std::string	command;
	srand(time(NULL));

	while (on)	{
		if (command == "exit")	{
			on = false;
		}
		else {
			try {
				Base*	base_ptr = generate();
				std::getline(std::cin, command);

				std::cout << "\nbase_pts -> ptr : ";
				identify(base_ptr);

				std::cout << "\nbase_pts -> ref : ";
				identify(*base_ptr);

				delete base_ptr;

			} catch (...) {
				std::cerr << "ERROR detected" << std::endl;
			}
		}
		std::cout << "\n\n\n\n";
	}

	return 0;
}
