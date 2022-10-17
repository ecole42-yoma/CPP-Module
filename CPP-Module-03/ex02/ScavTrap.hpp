/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 03:42:48 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 17:37:58 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAV_TRAP__
# define __SCAV_TRAP__

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap	{

	public:
		ScavTrap(const std::string& name	= "Scav_Init_Name",
					const int& hit_point	= 100,
					const int& energy_point	= 50,
					const int& attack_point	= 20);
		virtual ~ScavTrap(void);
		ScavTrap(const ScavTrap& from);
		ScavTrap& operator=(const ScavTrap& operand);

		virtual void		attack(const std::string& target);
		void				guardGate(void) const;

};	/* ScavTrap */

#endif /* __SCAV_TRAP_ */
