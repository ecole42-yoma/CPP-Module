/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:35:05 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/08 05:53:22 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip>

namespace	{

	void	_newZombie(std::string const& name, int size)	{
		std::cout << "\n------- ZombieHorde Start ! -------" << std::endl;
		ft::Zombie*	zombie = ft::zombieHorde(size, name);
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "------- Total : " << std::setw(3) << ft::Zombie::GetCount() << " ---------------" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "------- Zombie Shouting ! ---------" << std::endl;
		for (int i = 0; i < size; i++)	{
			zombie[i].announce();
		}
		std::cout << "--------- Zombie Gone ! -----------" << std::endl;
		delete[] zombie;
		std::cout << "------------------------------------" << std::endl;
	}

	bool	_IsThereOnlyDigit(std::string const& input_size)	{
		for (std::size_t i = 0; i < input_size.length(); i++)	{
			if (!isdigit(input_size[i]))	{
				return false;
			}
		}
		return true;
	}

	void	_CheckName(std::string& name)	{
		while (true)	{
			std::cout << "\n [ name ] of zombies" << std::endl;
			std::cout << "> ";
			std::getline(std::cin, name);
			if (name.empty())	{
				continue ;
			}
			else	{
				break ;
			}
		}
	}

	bool	_CheckMore(std::string& cmd)	{
		while (true)	{
			std::cout << "\n Wanna try more test? ( y / n )" << std::endl;
			std::cout << "> ";
			std::getline(std::cin, cmd);
			if (cmd == "y")	{
				break ;
			}
			else if (cmd == "n")	{
				return true;
			}
		}
		return false;
	}

}	/* namespace */


int main(void)	{
	std::string	name;
	std::string	input_size;
	int			int_size;

	while (true)	{
		std::cout << "\n [ number ] of zombies" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input_size);
		if (input_size == "exit")	{
			return 0;
		}
		if (!_IsThereOnlyDigit(input_size))	{
			std::cout << "There aren't only digit character" << std::endl;
			continue ;
		}
		std::stringstream(input_size) >> int_size;
		if (int_size < 0)	{
			std::cout << "Plz enter valid number" << std::endl;
			continue ;
		}
		_CheckName(name);
		_newZombie(name, int_size);
		if (_CheckMore(name))	{
			return 0;
		}
	}
}
