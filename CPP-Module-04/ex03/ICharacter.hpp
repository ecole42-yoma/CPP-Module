/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:39:01 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 16:27:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ICHARACTER__HPP__
# define __ICHARACTER__HPP__

# include <string>

class AMateria;

class ICharacter	{

	public:
		virtual ~ICharacter() {}
		virtual std::string const&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;

};

#endif
