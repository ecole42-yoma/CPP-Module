/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:41:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 17:43:28 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

namespace	{

	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[FragTrap] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}

}

FragTrap::FragTrap(const std::string& name,
					const int& hit_point,
					const int& energy_point,
					const int& attack_point)
: ClapTrap(name, hit_point, energy_point, attack_point)	{
	_PrintMsg("Default constructor called", getName());
}

FragTrap::~FragTrap(void)	{
	_PrintMsg("Destructor called", getName());
}

FragTrap::FragTrap(const FragTrap& from)
: ClapTrap("Frag_Copy_Name")	{
	_PrintMsg("Copy constructor called", getName());
	*this = from;
}

FragTrap& FragTrap::operator=(const FragTrap& operand)	{
	_PrintMsg("Copy assignment operator called", getName());
	ClapTrap::operator=(operand);
	return *this;
}

void	FragTrap::attack(const std::string& target)	{
	if (0 < getEnergy() && 0 < getHealth())	{
		_setEnergy(getEnergy() - 1);
		std::cout << "FragTrap [" << getName() << "] attacks [" << target << "], causing " << getDamage() << " points of damage!" << std::endl;
		std::cout << "         [" << getName() << "]'s energy points [ " << getEnergy() << " ]" << std::endl;
	}
	else {
		if (getEnergy() == 0)
			_setEnergy(getEnergy() - 1);
		if (getEnergy() < 0)
			std::cout << "[attack] " << "FragTrap [" << getName() << "] needs energy points. [now energy : " << getEnergy() << " ]" << std::endl;
		else if (getHealth() <= 0)
			std::cout << "[attack] " << "FragTrap [" << getName() << "] is zombie.." << std::endl;
	}
}

void	FragTrap::highFivesGuys(void) const	{
	std::cout << "FragTrap " << getName() << "is request HiveFives!" << std::endl;
}
