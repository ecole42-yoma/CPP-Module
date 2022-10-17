/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:50:30 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:30:57 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __HUMAN_B_HPP__
# define __HUMAN_B_HPP__

# include <string>
# include "Weapon.hpp"

class	HumanB	{

	private:
		const std::string	name_;
		Weapon*				weapon_;

	public:
		explicit HumanB(std::string const& name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);

};

#endif /* __HUMAN_B_HPP__ */
