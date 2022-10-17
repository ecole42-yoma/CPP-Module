/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:51:08 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:31:04 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#ifndef __HUMAN_A_HPP__
# define __HUMAN_A_HPP__

# include <string>
# include "Weapon.hpp"

class	HumanA	{

	private:
		const std::string	name_;
		Weapon&				weapon_;

	public:
		explicit HumanA(std::string const& name, Weapon& weapon);
		~HumanA(void);
		void	attack(void) const;

};

#endif /* __HUMAN_A_HPP__ */
