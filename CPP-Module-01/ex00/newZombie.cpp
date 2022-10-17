/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:49:52 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:45:34 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

ft::Zombie*	ft::newZombie(std::string const& name)	{
	return new ft::Zombie(name);
}
