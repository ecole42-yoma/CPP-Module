/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:35:05 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/08 05:15:13 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

namespace	{

	void	_newZombie(const std::string& name)	{
		std::cout << "\n------- newZombie  - heap area -------" << std::endl;
		ft::Zombie*	zombie = ft::newZombie(name);
		delete zombie;
		std::cout << "--------------------------------------" << std::endl;
	}

	void	_randomChump(const std::string& name)	{
		std::cout << "\n------- randomChump - stack area -------" << std::endl;
		ft::randomChump(name);
		std::cout << "----------------------------------------\n\n" << std::endl;
	}

}	/* namespace end */

int main(void)	{
	std::string name;

	while (true)	{
		std::cout << "\nEnter the name of the zombie" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, name);
		if (name == "exit")	{
			break ;
		}
		_newZombie(name);
		_randomChump(name);
	}
}
