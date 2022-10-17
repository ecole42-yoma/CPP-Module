/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:58:44 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 21:05:14 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DIAMOND_TRAP__
# define __DIAMOND_TRAP__

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap	{

	private:
	std::string		name_;

	public:
	explicit DiamondTrap(const std::string& name	= "Diamond_Init_Name");
	virtual ~DiamondTrap(void);
	DiamondTrap(const DiamondTrap& from);
	DiamondTrap&	operator=(const DiamondTrap& operand);

	void				whoAmI(void) const;
	virtual	void		attack(const std::string& target);
	virtual std::string	getName(void) const;

};

#endif /* __DIAMOND_TRAP__ */
