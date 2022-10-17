/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:38:19 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:44:41 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

ft::Zombie::Zombie(void) : name_("Noname")	{	}

ft::Zombie::Zombie(const std::string& name) : name_(name)	{
	announce();
}

ft::Zombie::~Zombie(void)	{
	std::cout << "Zombie \'" << name_ << "\' is gone" << std::endl;
}

void	ft::Zombie::announce(void) const	{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
