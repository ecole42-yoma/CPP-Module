/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:52:37 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 19:09:05 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[ClapTrap] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

void	ClapTrap::_setName(const std::string& name)	{	name_ = name;	}
void	ClapTrap::_setHealth(int scalar)			{	health_ = scalar;	}
void	ClapTrap::_setEnergy(int scalar)			{	energy_ = scalar;	}
void	ClapTrap::_setDamage(int scalar)			{	damage_ = scalar;	}

ClapTrap::ClapTrap(std::string const& name,
					const int& hit_point,
					const int& energy_point,
					const int& attack_point)
: name_(name),
health_(hit_point),
energy_(energy_point),
damage_(attack_point)	{
	/* start here */
	_PrintMsg("Default constructor called", name_);
}

ClapTrap::~ClapTrap(void)	{	_PrintMsg("Destructor called", name_);	}

ClapTrap::ClapTrap(ClapTrap const& from)
: name_("Clap_Copy_Name")	{
	_PrintMsg("Copy constructor called", name_);
	*this = from;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& operand)	{
	_PrintMsg("Copy assignment operator called", name_);
	_setName(operand.ClapTrap::getName());
	_setHealth(operand.ClapTrap::getHealth());
	_setEnergy(operand.ClapTrap::getEnergy());
	_setDamage(operand.ClapTrap::getDamage());
	return *this;
}

void	ClapTrap::attack(const std::string& target)	{
	if (0 < energy_ && 0 < health_)	{
		energy_ -= 1;
		std::cout << "ClapTrap [" << name_ << "] attacks [" << target << "], causing " << damage_ << " points of damage!" << std::endl;
		std::cout << "         [" << name_ << "]'s energy points [ " << energy_ << " ]" << std::endl;
	}
	else {
		if (energy_ == 0)
			_setEnergy(getEnergy() - 1);
		if (energy_ < 0)
			std::cout << "[attack] " << "ClapTrap [" << name_ << "] needs energy points. [now energy : " << energy_ << " ]" << std::endl;
		else if (health_ <= 0)
			std::cout << "[attack] " << "ClapTrap [" << name_ << "] is zombie.." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)	{
	if (0 < health_)	{
		health_ -= amount;
		std::cout << "ClapTrap [" << name_ << "] be damaged " << damage_ << " points of damage! [now health : " << health_ << " ]" << std::endl;
	}
	else	{
		std::cout << "ClapTrap [" << name_ << "] is already dead. Stop Teabagging" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)	{
	if (0 < energy_ && 0 < health_)	{
		health_ += amount;
		_setEnergy(getEnergy() - 1);
		std::cout << "ClapTrap [" << name_ << "] repaired " << amount << " points of health [now health : " << health_ << " ]" << std::endl;
		std::cout << "         [" << name_ << "]'s energy points [ " << energy_ << " ]" << std::endl;
	}
	else {
		if (energy_ == 0)
			_setEnergy(getEnergy() - 1);
		if (energy_ < 0)
			std::cout << "[beRepaired] " << "ClapTrap [" << name_ << "] needs energy points. [now energy : " << energy_ << " ]" << std::endl;
		else if (health_ <= 0)
			std::cout << "[beRepaired] " << "ClapTrap [" << name_ << "] is zombie.." << std::endl;
	}
}

int			ClapTrap::getDamage(void)	const	{	return damage_;	}
int			ClapTrap::getHealth(void)	const	{	return health_;	}
int			ClapTrap::getEnergy(void)	const	{	return energy_;	}
std::string	ClapTrap::getName(void)		const	{	return name_;	}
