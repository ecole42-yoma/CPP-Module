/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:21:43 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/21 18:19:08 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main_2()	{

	try {
		Bureaucrat	first("First", 1);

		std::cout << "\n\n ShrubberyCreation Form test :: -----------------\n" << std::endl;
		ShrubberyCreationForm	sh("ASCII TREE");
		try {
			Bureaucrat	employee("sh_137", 137);
			employee.executeForm(sh);
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;


		try {
			Bureaucrat	employee("sh_146", 146);
			employee.executeForm(sh);
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;

		try {
			first.signForm(sh);
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n now shrubbery -----------------\n" << std::endl;
		std::cin.get();

		try {
			Bureaucrat	employee("sh_137", 137);
			employee.executeForm(sh);
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;


		std::cout << "\n\n Robotomy Request Form test :: -----------------\n" << std::endl;
		std::cin.get();
		RobotomyRequestForm robot("ROBO!");

		try {
			Bureaucrat employee("ro_73", 73);
			employee.signForm(robot);
		} catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;
		std::cin.get();

		try {
			Bureaucrat employee("ro_72", 72);
			employee.signForm(robot);
			employee.executeForm(robot);
		} catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;
		std::cin.get();

		try {
			Bureaucrat employee("ro_46", 46);
			employee.signForm(robot);
			for (std::size_t i = 0; i < 42; ++i)	{
				std::cout << std::endl;
				employee.executeForm(robot);
			}
		} catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;
		std::cin.get();

		try {
			Bureaucrat employee("ro_46", 46);
			employee.levelUp();
			employee.levelUp();
			employee.levelUp();
			std::cout << employee << std::endl;
			std::cout << robot << std::endl;
			std::cin.get();
			employee.signForm(robot);
			for (std::size_t i = 0; i < 42; ++i)	{
				std::cout << std::endl;
				employee.executeForm(robot);
			}
		} catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;


		std::cout << "\n\n Presidential Pardon Form test :: -----------------\n" << std::endl;
		std::cin.get();
		PresidentialPardonForm presi("Mr.Zero");

		try {
			Bureaucrat employee("pre_26", 26);
			std::cout << employee << std::endl;
			std::cout << presi << std::endl;
			employee.signForm(presi);
			employee.executeForm(presi);
		} catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;
		std::cin.get();


		try {
			Bureaucrat employee("pre_24", 24);
			std::cout << employee << std::endl;
			std::cout << presi << std::endl;
			employee.signForm(presi);
			employee.executeForm(presi);
		} catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}
		std::cout << "\n-----------------\n" << std::endl;
		std::cin.get();


		try {
			std::cout << first << std::endl;
			std::cout << presi << std::endl;
			first.signForm(presi);
			first.executeForm(presi);
		} catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		} catch (std::string e)	{
			std::cerr << e << std::endl;
		}

		std::cout << "\n\n Intern test :: -----------------\n" << std::endl;
		std::cin.get();

		try {
			Intern	no_pay_intern;
			Form* rrf;

			rrf = no_pay_intern.makeForm("robo", "Bender");

			first.signForm(*rrf);
			first.executeForm(*rrf);
			delete rrf;

			rrf = no_pay_intern.makeForm("pres", "Elon Musk");
			first.signForm(*rrf);
			first.executeForm(*rrf);
			delete rrf;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		catch(std::string const& e)	{
			std::cerr << e << '\n';
		}

		std::cout << "\n\n Intern test_2 :: -----------------\n" << std::endl;
		std::cin.get();

		try {
			Intern	no_pay_intern;
			Form* rrf;

			rrf = no_pay_intern.makeForm("shru", "CIICII_BASE");

			first.signForm(*rrf);
			first.executeForm(*rrf);

			delete rrf;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		catch(std::string const& e)	{
			std::cerr << e << '\n';
		}




		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Detected error : " << e.what() << '\n';
	} catch (...)	{
		std::cerr << "Different Case.." << std::endl;
	}
	return 0;
}

int main()	{
	main_2();

	std::cout << "Leaks check! " << std::endl;
	std::cin.get();

	return 0;
}
