/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:21:43 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/21 17:53:43 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main_2()	{

	try {

		try {
			Form	project_test("ok", 1, 1);
		} catch (std::exception const& e) {
			std::cerr << "[ERROR] Form parameter size out :: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cin.get();

		try {
			Form	project_test("first lower", 151, 1);
		} catch (std::exception const& e) {
			std::cerr << "[ERROR] Form parameter size out :: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cin.get();

		try {
			Form	project_test("first higher", 0, 1);
		} catch (std::exception const& e) {
			std::cerr << "[ERROR] Form parameter size out :: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cin.get();

		try {
			Form	project_test("second lower", 1, 151);
		} catch (std::exception const& e) {
			std::cerr << "[ERROR] Form parameter size out :: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cin.get();

		try {
			Form	project_test("second higher", 1, 0);
		} catch (std::exception const& e) {
			std::cerr << "[ERROR] Form parameter size out :: " << e.what() << std::endl;
		}
		std::cin.get();

		std::cout << "\n-----------------\n" << std::endl;
		Bureaucrat	first("First", 1);
		Bureaucrat	last("Last", 150);
		Bureaucrat	employee("employee", 140);
		Form		project("project nova : LV.139", 139, 139);
		std::cout << project << std::endl;
		std::cout << std::endl;
		std::cin.get();

		std::cout << "\n\n-----------------\n" << std::endl;
		std::cout << first << std::endl;
		first.signForm(project);
		std::cout << project << std::endl;
		std::cin.get();

		std::cout << "\n-----------------\n" << std::endl;
		std::cout << last << std::endl;
		last.signForm(project);
		std::cout << project << std::endl;
		std::cin.get();

		std::cout << "\n-----------------\n" << std::endl;
		std::cout << employee << std::endl;
		employee.signForm(project);
		std::cout << project << std::endl;
		std::cout << std::endl;
		std::cin.get();

		employee.levelUp();
		std::cout << employee << std::endl;
		employee.signForm(project);
		std::cin.get();

		std::cout << "\n-----------------\n" << std::endl;
		first.signForm(project);
		std::cin.get();



		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Detected error : " << e.what() << '\n';
	} catch (...)	{
		std::cerr << "Different Case.." << std::endl;
	}
	return 0;
}

int main()	{

	{
		main_2();
	}
	std::cout << "check leaks" << std::endl;
	std::cin.get();
	return 0;
}
