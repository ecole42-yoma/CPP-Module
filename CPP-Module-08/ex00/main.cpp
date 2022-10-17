/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:57:30 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 09:20:37 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "iostream"
#include "vector"
#include "list"
#include "map"

template <class T>
void	check_value(T& container, int n)	{
	std::cout << "[non const] ";
	typename T::iterator it = easyfind(container, n);
	if (it == container.end())
		std::cerr << "Not found " << n << " in container" << std::endl;
	else
		std::cout << "Found " << *it << " in container" << std::endl;
}

template <class T>
void	check_value(const T& container, int n)	{
	std::cout << "[const] ";
	typename T::const_iterator it = easyfind(container, n);
	if (it == container.end())
		std::cerr << "Not found " << n << " in container" << std::endl;
	else
		std::cout << "Found " << *it << " in container" << std::endl;
}

template <>
void	check_value< std::map<int, int> >(std::map<int, int>& container, int n)	{
	std::cout << "[non const] ";
	std::map<int, int>::iterator it = easyfind(container, n);
	if (it == container.end())
		std::cerr << "Not found key[" << n << "] in container" << std::endl;
	else
		std::cout << "Found key[" << it->first << "]: " << it->second << " in container" << std::endl;
}

template <>
void	check_value< std::map<int, int> >(const std::map<int, int>& container, int n)	{
	std::cout << "[const] ";
	std::map<int, int>::const_iterator it = easyfind(container, n);
	if (it == container.end())
		std::cerr << "Not found key[" << n << "] in container" << std::endl;
	else
		std::cout << "Found key[" << it->first << "]: " << it->second << " in container" << std::endl;
}



template <class T>
void	gen_struct(std::string const& type)	{
	std::cout << "\n" << type << " test   :" << std::endl;
	std::cout << "[non_const]" << std::endl;
	T container;
	try {

		for (int i = 0; i <= 42; ++i)	{
			container.insert(container.end(), i);
		}
		check_value(container, 0);
		check_value(container, 42);
		check_value(container, 43);
		check_value(container, -1);
	} catch (int e)	{
		std::cout << "Error : " << e << std::endl;
	} catch (...) {
		std::cerr << "error ocurred" << std::endl;
	}

	std::cout << "[const]" << std::endl;
	try {
		const T c_container = container;

		check_value(c_container, 0);
		check_value(c_container, 42);
		check_value(c_container, 43);
		check_value(c_container, -1);
	} catch (int e)	{
		std::cout << "Error : " << e << std::endl;
	} catch (...) {
		std::cerr << "error ocurred" << std::endl;
	}
}

template <>
void	gen_struct< std::map<int, int> >(std::string const& type)	{
	std::cout << "\n" << type << " test   :" << std::endl;
	std::cout << "[non_const]" << std::endl;
	std::map<int, int> container;
	try {
		for (int i = 0; i <= 42; ++i)	{
			container.insert(std::pair<int, int>(i, i * 100));
		}
		check_value(container, 0);
		check_value(container, 42);
		check_value(container, 43);
		check_value(container, -1);
	} catch (int e)	{
		std::cout << "Error : " << e << std::endl;
	} catch (...) {
		std::cerr << "error ocurred" << std::endl;
	}

	try {
		std::cout << "[const]" << std::endl;
		const std::map<int, int> c_container = container;
		check_value(c_container, 0);
		check_value(c_container, 42);
		check_value(c_container, 43);
		check_value(c_container, -1);
	} catch (int e)	{
		std::cout << "Error : " << e << std::endl;
	} catch (...) {
		std::cerr << "error ocurred" << std::endl;
	}
}

int main_2()	{

	gen_struct< std::vector<int> >("vector");
	std::cin.get();

	gen_struct< std::list<int> >("list");
	std::cin.get();

	gen_struct< std::map<int, int> >("map");
	std::cin.get();

	return 0;
}

int main()	{

	main_2();
	std::cout << "check leaks" << std::endl;
	std::cin.get();

	return 0;
}
