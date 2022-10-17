/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:08:54 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/15 20:00:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

namespace	{

	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[DiamondTrap] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}

}

DiamondTrap::DiamondTrap(const std::string& name)
:ClapTrap(name + "_clap_name"),
name_(name)	{
	_PrintMsg("Default constructor called", DiamondTrap::getName());
	_setHealth(FragTrap::kInitHitPoint);
	_setEnergy(ScavTrap::kInitEnergyPoint);
	_setDamage(FragTrap::kInitAttackPoint);
}

DiamondTrap::~DiamondTrap(void)	{
	_PrintMsg("Destructor called", DiamondTrap::getName());
}

DiamondTrap::DiamondTrap(const DiamondTrap& from)
: ClapTrap("Diamond_Clap_Copy_Name"),
name_("Diamond_Copy_Name")	{
	_PrintMsg("Copy constructor called", DiamondTrap::getName());
	*this = from;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& operand)	{
	_PrintMsg("Copy assignment operator called", DiamondTrap::getName());
	ClapTrap::operator=(operand);
	name_ = operand.getName();
	return *this;
}

void		DiamondTrap::attack(const std::string& target)	{	ScavTrap::attack(target);	}
std::string	DiamondTrap::getName(void) const				{	return name_;	}

void	DiamondTrap::whoAmI(void) const	{
	std::cout << "My DiamondTrap name is [" << DiamondTrap::getName() << "]" << std::endl;
	std::cout << "   My ClapTrap name is [" << ClapTrap::getName() << "]" << std::endl;
}
