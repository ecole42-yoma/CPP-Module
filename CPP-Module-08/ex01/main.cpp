/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:24:27 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 10:24:08 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <limits>

int main_3(unsigned int test_size, bool show)
{
	std::cout << "\n" << test_size << " test   ========================" << std::endl;
	try {
		std::srand(time(NULL));
		Span	sp = Span(test_size);
		bool	sign = true;
		int		sign_indicator = 1;

		int		max_cycle = static_cast<int>(test_size / 2);
		for (int i = 0; i < max_cycle; i++)	{
			if (sign)	{
				sign = false;
				sign_indicator = 1;
			}
			else	{
				sign = true;
				sign_indicator = -1;
			}
			sp.addNumber(static_cast<int>((std::rand() % INT_MAX) / 2) + static_cast<int>((std::rand() % INT_MAX) / 2) * sign_indicator);
		}
		sp.addNumberRepeat(max_cycle);

		std::cout << "span size = " << sp.getSize() << std::endl;
		std::cout << "[shortest span] " << sp.shortestSpan() << std::endl;
		std::cout << "[longest span] " << sp.longestSpan() << std::endl;
		if (show)	{
			std::cout << "[get list] " << std::endl;
			sp.show();
		}

		Span copy = sp;
		std::string cmd;
		std::cout << "\ncopy version, wanna see?" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd == "y" || cmd == "Y" || cmd == "YES" || cmd == "yes")	{
			std::cout << "span size = " << copy.getSize() << std::endl;
			std::cout << "[shortest span] " << copy.shortestSpan() << std::endl;
			std::cout << "[longest span] " << copy.longestSpan() << std::endl;
			if (show)	{
				std::cout << "[get list] " << std::endl;
				copy.show();
			}
		}

	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

int main_2()
{
	std::cout << "========================" << std::endl;
	try {
		Span sp = Span(6);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

int main_4()
{
	std::cout << "========================" << std::endl;
	try {
		Span sp = Span(6);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}


int main_1()
{
	std::cout << "========================" << std::endl;
	try {
		Span sp = Span(6);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(2147483647);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

int main(int argc, char **argv)	{

	main_2();
	main_4();
	main_1();
	if (argc == 1)
		main_3(10000, false);
	else	{
		std::stringstream ss(argv[1]);

		unsigned int test_size;
		ss >> test_size;

		main_3(test_size, true);
	}
	std::cout << "\ncheck leaks" << std::endl;
	std::cin.get();

	return 0;
}
