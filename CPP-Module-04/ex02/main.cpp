/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:36:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:52:37 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <sstream>

namespace  {
	std::string	_toString(const std::size_t& num)	{
		std::stringstream	ss;
		ss << num;
		return ss.str();
	}

}

int main_2(int argc, char **argv) {
	size_t	max = 21;

	if (argc != 1)	{
		std::stringstream ss(argv[1]);

		ss >> max;
	}
	if (max > 21)
		max = 21;
	if (max < 1)
		max = 7;	std::cout << "inner org create" << std::endl;

	// AAnimal* temp = AAnimal(); // should be error abstract class
	// AAnimal temp_2();

	std::cout << "max: " << max << std::endl;
	{
		std::cout << "\n\nnew 2 instant and del 2" << std::endl;
		std::cin.get();

		const AAnimal* j = new Dog();
		j->makeSound();
		const AAnimal* i = new Cat();
		i->makeSound();

		delete j;//should not create a leak
		delete i;
	}

	{
		std::cout << "\n\nnew 2 instant and del 2 with name" << std::endl;
		std::cin.get();

		AAnimal* j = new Dog("Jindo");
		j->makeSound();
		AAnimal* i = new Cat("Nabi");
		i->makeSound();

		std::cout << "\n\nPrint ideas, this func not within AAnimal class" << std::endl;
		std::cin.get();
		// j->printIdeas(); // not in scope
		// i->printIdeas();
		dynamic_cast<Dog*>(j)->printIdeas(); // for using child function, should be casted
		dynamic_cast<Cat*>(i)->printIdeas();

		delete j;
		delete i;

	}

	{
		std::cout << "\n\ntest mutiple instance" << std::endl;
		std::cin.get();

		AAnimal* animal[21];

		std::cout << "\n\n[new]" << std::endl;
		std::cin.get();
		for (std::size_t i = 0; i < max; ++i)	{
			if (i & 1)	{
				animal[i] = new Dog();
				std::cout << _toString(i) << "] ";
				animal[i]->makeSound();
				std::cout << "\n" << std::endl;
			}
			else	{
				animal[i] = new Cat();
				std::cout << _toString(i) << "] ";
				animal[i]->makeSound();
				std::cout << "\n" << std::endl;
			}
		}

		std::cout << "\n\n[brain]" << std::endl;
		std::cin.get();
		for (std::size_t i = 0; i < max; ++i)	{
			for (std::size_t j = 0; j < 10; ++j)	{
				if (i & 1)	{
					std::cout << "Dog[" << _toString(i) << "] " << " brain-" << j << ": "<< (dynamic_cast<Dog *>(animal[i]))->getBrain(j) << std::endl;
				}
				else	{
					std::cout << "Cat[" << _toString(i) << "] " << " brain-" << j << ": "<< (dynamic_cast<Cat *>(animal[i]))->getBrain(j) << std::endl;
				}
			}
			std::cout << "                     ." << std::endl;
			std::cout << "                     ." << std::endl;
			std::cout << "                     ." << std::endl;
			std::cout << "                     ." << std::endl;
			std::cout << "                     ." << std::endl;
			for (std::size_t j = 90; j < 100; ++j)	{
				if (i & 1)	{
					std::cout << "Dog[" << _toString(i) << "] " << " brain-" << j << ": "<< (dynamic_cast<Dog *>(animal[i]))->getBrain(j) << std::endl;
				}
				else	{
					std::cout << "Cat[" << _toString(i) << "] " << " brain-" << j << ": "<< (dynamic_cast<Cat *>(animal[i]))->getBrain(j) << std::endl;
				}
			}
			std::cout << std::endl;
		}
		std::cout << "------------------------\n\n" << std::endl;
		std::cout << "\n\n[del]" << std::endl;
		std::cin.get();
		for (std::size_t i = 0; i < max; ++i)	{
			delete animal[i];
			std::cout << _toString(i) << "\n" << std::endl;
		}
	}

	return 0;
}

int main(int argc, char **argv) {
	main_2(argc, argv);
	std::cout << "check leaks!" << std::endl;
	std::cin.get();
	return 0;
}
