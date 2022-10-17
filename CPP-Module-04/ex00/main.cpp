/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:39:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:19:30 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)	{

	{
		std::cout << "--- correct case ---" << std::endl;
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << "\n\n[" << meta->getType() << "]" << std::endl;
		meta->makeSound();
		std::cout << "\n[" << dog->getType() << "]" << std::endl;
		dog->makeSound();
		std::cout << "\n[" << cat->getType() << "]" << std::endl;
		cat->makeSound();
	}
	{
		std::cout << "\n\n--- wrong case ---" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* cat_1 = new WrongCat();	// Upcasting Problem
		const WrongCat* cat_2 = new WrongCat();

		std::cout << "\n\n[" << meta->getType() << "]" << std::endl;
		meta->makeSound();
		std::cout << "\n[" << cat_1->getType() << "]" << std::endl;
		cat_1->makeSound();
		std::cout << "\n[" << cat_2->getType() << "]" << std::endl;
		cat_2->makeSound();
	}
	return 0;
}
