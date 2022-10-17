/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:42:43 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:15:32 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>

class	Weapon	{

	private:
		std::string	type_;

	public:
		Weapon(void);
		explicit Weapon(std::string const& type);
		~Weapon(void);
		const std::string&	getType(void) const;
		void				setType(std::string const& type);

};

#endif /* __WEAPON_HPP__ */
