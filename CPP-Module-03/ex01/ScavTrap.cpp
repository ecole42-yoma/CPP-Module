/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 03:49:56 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 17:35:49 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

namespace	{

	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[ScavTrap] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}

}

ScavTrap::ScavTrap(const std::string& name,
					const int& hit_point,
					const int& energy_point,
					const int& attack_point)
: ClapTrap(name, hit_point, energy_point, attack_point)	{
	_PrintMsg("Default constructor called", getName());
}

ScavTrap::~ScavTrap(void)	{
	_PrintMsg("Destructor called", getName());
}

ScavTrap::ScavTrap(const ScavTrap& from)
: ClapTrap("Scav_Copy_Name")	{
	_PrintMsg("Copy constructor called", getName());
	*this = from;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& operand)	{
	_PrintMsg("Copy assignment operator called", getName());
	ClapTrap::operator=(operand);
	return *this;
}

void	ScavTrap::attack(const std::string& target)	{
	if (0 < getEnergy() && 0 < getHealth())	{
		_setEnergy(getEnergy() - 1);
		std::cout << "ScavTrap [" << getName() << "] attacks [" << target << "], causing " << getDamage() << " points of damage!" << std::endl;
		std::cout << "         [" << getName() << "]'s energy points [ " << getEnergy() << " ]" << std::endl;
	}
	else {
		if (getEnergy() == 0)
			_setEnergy(getEnergy() - 1);
		if (getEnergy() < 0)
			std::cout << "[attack] " << "ScavTrap [" << getName() << "] needs energy points. [now energy : " << getEnergy() << " ]" << std::endl;
		else if (getHealth() <= 0)
			std::cout << "[attack] " << "ScavTrap [" << getName() << "] is zombie.." << std::endl;
	}
}

void	ScavTrap::guardGate(void) const	{
	std::cout << "ScavTrap " << getName() << "is now in Gate keeper mode." << std::endl;
}
