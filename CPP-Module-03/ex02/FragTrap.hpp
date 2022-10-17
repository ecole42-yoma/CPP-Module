/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:04:43 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 17:37:39 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAG_TRAP__
# define __FRAG_TRAP__

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap	{

	public:
		FragTrap(const std::string& name	= "Frag_Init_Name",
					const int& hit_point	= 100,
					const int& energy_point	= 100,
					const int& attack_point	= 30);
		virtual ~FragTrap(void);
		FragTrap(const FragTrap& from);
		FragTrap& operator=(const FragTrap& operand);

		virtual void		attack(const std::string& target);
		void				highFivesGuys(void) const;

};

#endif /* __FRAG_TRAP__ */
