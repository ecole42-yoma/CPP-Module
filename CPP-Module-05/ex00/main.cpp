/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:21:43 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/21 17:45:29 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main_2()	{

	try {
		Bureaucrat first("First", 1);
		Bureaucrat last("Last", 150);
		// Bureaucrat test_1("test_1", 0);

		try {
			first.levelDown();
			first.levelUp();
			first.levelUp();
			std::cout << "---\n";
			first.levelDown();
		}
		catch(std::exception const& e) {
			std::cerr << "[ERROR] There is no more High place :: " << e.what() << '\n';
		}
		std::cin.get();


		try {
			last.levelUp();
			last.levelDown();
			last.levelDown();
			std::cout << "---\n";
			last.levelUp();
		}
		catch (std::exception const& e)	{
			std::cerr << "[ERROR] There is no more Low place :: " << e.what() << '\n';
		}
		std::cin.get();

		try {
			first.levelDown();
			std::cout << "\nNow " << first.getName() << "'s Info" << std::endl;
			std::cout << first << std::endl;

			throw 1; // int type throw
		}
		catch (std::exception const& e)	{
			std::cerr << "[ERROR] Occured :: " << e.what() << '\n';
		}
		catch (...)	{
			std::cerr << "Different Case.." << std::endl;
		}
		std::cin.get();


		try {
			last.levelUp();
			last.levelUp();
			last.levelUp();
			std::cout << "\nNow " << last.getName() << "'s Info" << std::endl;
			std::cout << last << std::endl;

		}
		catch (std::exception const& e)	{
			std::cerr << "[ERROR] Occured :: " << e.what() << '\n';
		}
		catch (...)	{
			std::cerr << "Different Case.." << std::endl;
		}
		std::cin.get();

	}
	catch (const std::exception& e) {
		std::cerr << "Detected error : " << e.what() << '\n';
	}
	return 0;

}

int main()	{

	main_2();
	std::cout << "check leaks" << std::endl;
	std::cin.get();
	return 0;
}
