/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:20:08 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 21:32:58 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CHARACTER__HPP__
# define __CHARACTER__HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

namespace ft {
	enum	Info{
		kSlotSize = 4
	};
}

class Character : public ICharacter	{

	private:
		const std::string			name_;
		AMateria*					slot_[ft::kSlotSize];

		std::size_t					floor_capacity_;
		mutable std::size_t			left_count_;
		AMateria**					floor_;

	public:
		explicit Character(std::string const& name = "Character_Name");
		Character(Character const& from);
		Character& operator=(Character const& operand);
		virtual ~Character();

		virtual std::string const&	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);

		std::size_t					getFloorCapacity() const;
		std::size_t					getLeftCount() const;
		AMateria*					getSlot(std::size_t idx) const;

		void						incLeftCount() const;
		void						setFloorCapacity(std::size_t capacity);
		void						setFloor(std::size_t idx, AMateria* m) const;
		void						resizeFloor();
		void						newFloor();


};

#endif

