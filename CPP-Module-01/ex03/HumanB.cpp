/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:00:49 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:29:57 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>


HumanB::HumanB(std::string const& name) : name_(name), weapon_(NULL)	{	}


HumanB::~HumanB(void)	{	}


void	HumanB::attack(void) const	{
	std::cout << name_ << " attacks with their ";
	if ( weapon_ )
		std::cout << weapon_->getType() << std::endl;
	else
		std::cout << "fist" << std::endl;
}


void	HumanB::setWeapon(Weapon& weapon)	{
	weapon_ = &weapon;
}
