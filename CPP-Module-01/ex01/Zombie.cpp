/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 05:26:51 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:42:01 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	ft::Zombie::count_;

ft::Zombie::Zombie(void)	{
	count_++;
	std::cout << "Zombie found! " << count_ << std::endl;
}

ft::Zombie::~Zombie(void)	{
	std::cout << "Zombie \'" << name_ << "\' is gone" << std::endl;
	count_--;
}

void	ft::Zombie::announce( void ) const	{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	ft::Zombie::initialize(std::string const& name, int id = -1)	{
	if (id < 0)	{
		name_ = name;
	}
	else	{
		name_ = name + "[" + std::to_string(id) + "]";
	}
}

int	ft::Zombie::GetCount(void)	{
	return count_;
}
