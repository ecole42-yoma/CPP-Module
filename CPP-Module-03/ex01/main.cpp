/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:31:32 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 17:35:58 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip>

namespace {

	std::string	_toString(int const& number)	{
		std::stringstream	stream;
		stream << number;
		return stream.str();
	}

	void	_printMsg(std::string const& msg, int const& width, int const& mode = 0)	{
		if (!mode)
			std::cout << std::right << std::setw(width) << std::setfill(' ') << msg;
		else
			std::cout << std::left << std::setw(width) << std::setfill(' ') << msg;
	}

	void	_printMsg(std::string const& msg)	{
		std::cout << msg;
	}

	void	_printMsgNewLine(std::string const& msg)	{
		std::cout << msg << std::endl;
	}

	void	_getPlayerName(std::string& a, std::string& b)	{
		_printMsg("\nenter the A's name : ");
		std::getline(std::cin, a);
		_printMsg("\nenter the B's name : ");
		std::getline(std::cin, b);
	}

	void	_makeUpper(std::string& str)	{
		for (std::string::iterator it = str.begin(); it != str.end(); it++)	{
			*it = std::toupper(*it);
		}
	}

	void	_getCommand(std::string& command, int mode = 0, std::string const& a = "No_name1", std::string const& b = "No_name2")	{
		switch (mode) {
			case 0:
				_printMsgNewLine("\n\n[A : attack] [H : heal] [S: status] [E : exit]");
				_printMsg(">> ");
				std::getline(std::cin, command);
				_makeUpper(command);
				break ;

			case 1:
				_printMsgNewLine("\n\nattacker : [1]" + a + "   [2]" + b + "   [S: status]  [E: exit]");
				_printMsg(">>> ");
				std::getline(std::cin, command);
				_makeUpper(command);
				break ;

			case 2:
				_printMsgNewLine("\n\nhelas to : [1]" + a + "   [2]" + b + "   [S: status]  [E: exit]");
				_printMsg(">>> ");
				std::getline(std::cin, command);
				_makeUpper(command);
				break ;

			default:
				break ;
		}
	}

	void	_statusCase(ScavTrap const& a, ScavTrap const& b)	{
		int size = a.getName().length();
		int size_2 = b.getName().length();
		size = size > size_2 ? size : size_2;

		if (size < 6)
			size = 13;
		else
			size += 8;
		_printMsgNewLine("\n\n[STATUS]\n");
		_printMsg("[" + a.getName() + "] info", size);
		_printMsg("[" + b.getName() + "] info\n", size + 8);

		_printMsg("hp     : ");
		_printMsg(_toString(a.getHealth()), 3);
		if (size > 13)
			_printMsg("", size - 7);
		else
			_printMsg("", size - 10);
		_printMsg("|");
		_printMsg("hp     : ", size);
		_printMsg(_toString(b.getHealth()) + "\n", 4);

		_printMsg("energy : ");
		_printMsg(_toString(a.getEnergy()), 3);
		if (size > 13)
			_printMsg("", size - 7);
		else
			_printMsg("", size - 10);
		_printMsg("|");
		_printMsg("energy : ", size);
		_printMsg(_toString(b.getEnergy()) + "\n", 4);

		_printMsg("demage : ");
		_printMsg(_toString(a.getDamage()), 3);
		if (size > 13)
			_printMsg("", size - 7);
		else
			_printMsg("", size - 10);
		_printMsg("|");
		_printMsg("demage : ", size);
		_printMsg(_toString(b.getDamage()) + "\n", 4);
	}

	void	_attackCase(int& exit_attack_status, ScavTrap& a, ScavTrap& b)	{
		std::string index;

		while (exit_attack_status)	{
			_getCommand(index, 1, a.getName(), b.getName());
			if (index.empty())	{
				_printMsgNewLine("command cannot be empty.");
				continue ;
			}
			else if (index == "1")	{
				a.attack(b.getName());
				if (0 < a.getHealth() && 0 <= a.getEnergy())	{
					b.takeDamage(a.getDamage());
				}
			}
			else if (index == "2")	{
				b.attack(a.getName());
				if (0 < b.getHealth() && 0 <= b.getEnergy())	{
					a.takeDamage(b.getDamage());
				}
			}
			else if (index == "EXIT" || index == "E")	{
				exit_attack_status = 0;
			}
			else if (index == "S" || index == "STATUS")	{
				_statusCase(a, b);
			}
			else {
				_printMsgNewLine("Invalid index\n");
				continue ;
			}
		}
	}

	void	_healCase(int& exit_heal_status, ScavTrap& a, ScavTrap& b)	{
		std::string index;

		while (exit_heal_status)	{
			_getCommand(index, 2, a.getName(), b.getName());
			if (index.empty())	{
				_printMsgNewLine("command cannot be empty.");
				continue ;
			}
			else if (index == "1")	{
				a.beRepaired(5);
			}
			else if (index == "2")	{
				b.beRepaired(5);
			}
			else if (index == "EXIT" || index == "E")	{
				exit_heal_status = 0;
			}
			else if (index == "S" || index == "STATUS")	{
				_statusCase(a, b);
			}
			else {
				_printMsgNewLine("Invalid index\n");
				continue ;
			}
		}
	}

}	/* namespace end */

int main(void)	{
	std::string	a_name;
	std::string	b_name;
	_getPlayerName(a_name, b_name);

	ScavTrap	A(a_name);
	std::cout << "and" << std::endl;
	ScavTrap	B(b_name); // case 1

	// ScavTrap	B(A); // case 2

	// ScavTrap	B; // case 3
	// B = A;

	int exit_status = 1;

	while (exit_status)	{
		std::string	command;
		int			exit_inner_status = 1;

		_getCommand(command);
		if (command.empty())	{
			_printMsgNewLine("command cannot be empty.");
			continue ;
		}
		else if (command == "ATTACK" || command == "A")	{
			_attackCase(exit_inner_status, A, B);
		}
		else if (command == "HEAL" || command == "H")	{
			_healCase(exit_inner_status, A, B);
		}
		else if (command == "STATUS" || command == "S")	{
			_statusCase(A, B);
		}
		else if (command == "EXIT" || command == "E")	{
			_printMsgNewLine("exit program.");
			return 0;
		}
		else {
			_printMsgNewLine("Invalid command\n");
			continue ;
		}
	}
	return 0;
}
