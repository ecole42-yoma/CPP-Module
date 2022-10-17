/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:49:52 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:35:44 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

ft::Zombie*	ft::zombieHorde(int N, std::string const& name)	{
	if (0 <= N)	{
		ft::Zombie*	zombies = new ft::Zombie[N];

		for (int i = 0; i < N; i++)	{
			zombies[i].initialize(name, i + 1);
		}
		return zombies;
	}
	return NULL;
}
