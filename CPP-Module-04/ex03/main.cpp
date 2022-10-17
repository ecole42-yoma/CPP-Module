/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:26:23 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/17 00:17:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

namespace	{

	void	_printMSG(const std::string& msg)	{
		if (msg == "")
			std::cout << std::endl;
		else
			std::cout << "\n\n[\033[1;42m" << msg << "\033[0m]" << std::endl;
	}

	void	_waitCmd()	{
		std::cin.get();
	}
}

int main_2()	{

	_printMSG("new Materia Source");
	_waitCmd();
	IMateriaSource* src = new MateriaSource();

	_printMSG("Learn Ice and Cure in Materia Source");
	_waitCmd();
	src->learnMateria(new Ice());
	_printMSG("");
	src->learnMateria(new Cure());

	_printMSG("new Character [me]");
	_waitCmd();
	ICharacter* me = new Character("me");

	AMateria* tmp;
	_printMSG("create Ice and Cure, then equip");
	_waitCmd();
	tmp = src->createMateria("ice");
	me->equip(tmp);
	_printMSG("");
	tmp = src->createMateria("cure");
	me->equip(tmp);

	_printMSG("new Character [bob]");
	_waitCmd();
	ICharacter* bob = new Character("bob");

	_printMSG("[me] use 0, 1 slot at bob");
	_waitCmd();
	me->use(0, *bob);
	me->use(1, *bob);

	{
		_printMSG("add 2, 3 item in slot");
		_waitCmd();
		_printMSG("Learn Fire and Curse in Materia Source");
		_waitCmd();
		src->learnMateria(new Ice("Fire"));
		_printMSG("");
		src->learnMateria(new Cure("Curse"));

		_printMSG("create Fire and Curse, then equip");
		_waitCmd();
		tmp = src->createMateria("Fire");
		me->equip(tmp);
		_printMSG("");
		tmp = src->createMateria("Curse");
		me->equip(tmp);

		_printMSG("[me] use 2, 3 slot at bob");
		_waitCmd();
		me->use(2, *bob);
		me->use(3, *bob);

		_printMSG("[me] use out of range slot at bob");
		_waitCmd();
		me->use(-1, *bob);
		me->use(4, *bob);
	}

	{
		_printMSG("Create out of range, equip unlearned materia");
		_waitCmd();
		_printMSG("Learn ultra_ice and ultra_cure in Materia Source");
		_waitCmd();
		AMateria* ultra_ice = new Ice("ultra_ice");
		src->learnMateria(ultra_ice);
		_printMSG("");
		AMateria* ultra_cure = new Cure("ultra_cure");
		src->learnMateria(ultra_cure);

		_printMSG("create ultra_ice and ultra_cure, then equip");
		_waitCmd();
		tmp = src->createMateria("ultra_ice");
		me->equip(tmp);
		_printMSG("");
		tmp = src->createMateria("ultra_cure");
		me->equip(tmp);

		_printMSG("[me] use 0, 1, 2, 3, 4, 5 slot at bob");
		_waitCmd();
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(4, *bob);
		me->use(5, *bob);

		_printMSG("unequip 0, 1 slot");
		_waitCmd();
		me->unequip(0);
		_printMSG("");
		me->unequip(1);

		_printMSG("equip ultra_ice, ultra_cure in 0, 1 slot not through MateriaSource");
		_waitCmd();
		me->equip(ultra_ice);
		_printMSG("");
		me->equip(ultra_cure);

		_printMSG("[me] use 0, 1 slot at bob");
		_waitCmd();
		me->use(0, *bob);
		me->use(1, *bob);

		_printMSG("unequip 0, 1, 2, 3 slot");
		_waitCmd();
		me->unequip(0);
		_printMSG("");
		me->unequip(1);
		_printMSG("");
		me->unequip(2);
		_printMSG("");
		me->unequip(3);

		_printMSG("[me] use 0, 1, 2, 3 slot at bob");
		_waitCmd();
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		_printMSG("[me] equit ice, cure, Fire, Curse");
		_waitCmd();
		me->equip(src->createMateria("ice"));
		_printMSG("");
		me->equip(src->createMateria("cure"));
		_printMSG("");
		me->equip(src->createMateria("Fire"));
		_printMSG("");
		me->equip(src->createMateria("Curse"));

		_printMSG("unequip 0, 1, 2, 3 slot");
		_waitCmd();
		me->unequip(0);
		_printMSG("");
		me->unequip(1);
		_printMSG("");
		me->unequip(2);
		_printMSG("");
		me->unequip(3);

		_printMSG("[me] equit Curse, Fire, cure, ice");
		_waitCmd();
		me->equip(src->createMateria("Curse"));
		_printMSG("");
		me->equip(src->createMateria("Fire"));
		_printMSG("");
		me->equip(src->createMateria("cure"));
		_printMSG("");
		me->equip(src->createMateria("ice"));

		_printMSG("[me] use 0, 1, 2, 3 slot at bob");
		_waitCmd();
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		_printMSG("unequip 0, 1, 2, 3 slot");
		_waitCmd();
		me->unequip(0);
		_printMSG("");
		me->unequip(1);
		_printMSG("");
		me->unequip(2);
		_printMSG("");
		me->unequip(3);

	}

	_printMSG("[end]");
	_waitCmd();
	delete bob;
	_printMSG("");
	delete me;
	_printMSG("");
	delete src;

	return 0;
}

int main()	{
	main_2();
	std::cout << "check leaks" << std::endl;
	_waitCmd();
	return 0;
}
