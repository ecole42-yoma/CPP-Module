/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:57:13 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:31:14 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const& name, Weapon& weapon) : name_(name), weapon_(weapon)	{	}

HumanA::~HumanA(void)	{	}

void	HumanA::attack(void) const	{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
