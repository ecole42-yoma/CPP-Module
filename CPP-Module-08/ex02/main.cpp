/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:58:27 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 13:03:58 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>
#include <list>
#include <iostream>

int main_2()
{
	std::list<int> mstack;
	// std::list<int>::const_reverse_iterator it;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	{
		std::cout << "\nlist pop" << std::endl;
		while (!s.empty())	{
			std::cout << s.back() << std::endl;
			s.pop_back();
		}
	}

	return 0;
}

int main_1()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	{
		std::cout << "\nstack pop" << std::endl;
		while (!s.empty())	{
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
	// {
	// 	std::stack<int>::iterator it = s.begin();
	// 	std::stack<int>::iterator ite = s.end();
	// 	while (it != ite)
	// 	{
	// 		std::cout << *it << std::endl;
	// 		++it;
	// 	}

	// }
	return 0;
}

void main_3()	{
	MutantStack<int>	mstack;
	for (int i = 0; i < 10; i++)
		mstack.push(i);

	std::cout << std::endl;
	for (MutantStack<int>::const_iterator it = mstack.cbegin(); it != mstack.cend(); it++)
		std::cout << *it << std::endl;

}

void main_4()	{
	MutantStack<int>	mstack;
	for (int i = 0; i < 10; i++)
		mstack.push(i);

	std::cout << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
		std::cout << *it << std::endl;

}

int main()	{
	std::cout << "[stack]" << std::endl;
	std::cin.get();
	main_1();

	std::cout << "\n\n[list]" << std::endl;
	std::cin.get();
	main_2();

	std::cout << "\n[stack const] 0 -> 9" << std::endl;
	std::cin.get();
	main_3();

	std::cout << "\n[stack rbegin] 9 -> 0" << std::endl;
	std::cin.get();
	main_4();

	std::cout << "\nleaks cheak" << std::endl;
	std::cin.get();
	return 0;
}
