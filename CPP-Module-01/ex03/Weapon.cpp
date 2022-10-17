/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:44:58 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:15:22 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void)	{	}


Weapon::Weapon(std::string const& type) : type_(type) {	}


Weapon::~Weapon(void) {	}


const std::string&	Weapon::getType(void) const	{
	return type_;
}


void	Weapon::setType(std::string const& type) {
	type_ = type;
}
