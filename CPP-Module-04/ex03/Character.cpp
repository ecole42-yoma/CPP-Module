/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:35:39 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 21:51:31 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include <iostream>
#include <sstream>

namespace	{

	std::string	_toString(int const& num)	{
		std::stringstream ss;
		ss << num;
		return ss.str();
	}

	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[\033[1;36mCharacter\033[0m] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}

	void	_cleanUpFloor(Character* org_ch, int const& con_idx)	{
		Character& ch = *org_ch;

		if (ch.getLeftCount() == 0)
			ch.newFloor();
		if (ch.getLeftCount() < ch.getFloorCapacity())	{
			ch.setFloor(ch.getLeftCount(), ch.getSlot(con_idx));
		}
		else {
			ch.resizeFloor();
			ch.setFloor(ch.getLeftCount(), ch.getSlot(con_idx));
		}
	}

}

Character::Character(std::string const& name)
: name_(name), floor_capacity_(ft::kSlotSize), left_count_(0), floor_(NULL)	{
	_PrintMsg("Default constructor called", name_);
	for (std::size_t i = 0; i < ft::kSlotSize; ++i)	{
		slot_[i] = NULL;
	}
}

Character::Character(Character const& from)
: name_(from.name_), floor_capacity_(ft::kSlotSize), left_count_(0), floor_(NULL)	{
	_PrintMsg("Copy constructor called", name_);
	for (std::size_t i = 0; i < ft::kSlotSize; ++i)	{
		slot_[i] = NULL;
	}
	*this = from;
}

Character&	Character::operator=(Character const& operand)	{
	_PrintMsg("Copy assignment operator called", name_);
	{
		Character temp;

		for (std::size_t i = 0; i < ft::kSlotSize; ++i)	{
			AMateria *m = slot_[i];
			slot_[i] = temp.slot_[i];
			temp.slot_[i] = m;
		}
	}
	for (std::size_t i = 0; i < ft::kSlotSize; ++i)	{
		if (operand.slot_[i])	{
			slot_[i] = operand.slot_[i]->clone();
		}
	}
	return *this;
}

Character::~Character()	{
	_PrintMsg("Destructor called", name_);
	for (std::size_t i = 0; i < ft::kSlotSize; ++i)	{
		if (slot_[i])	{
			delete slot_[i];
		}
	}
	if (floor_)	{
		for (std::size_t i = 0; i < left_count_; ++i)	{
			_PrintMsg("[\033[1;46mCleanUp floor item \033[0m]", floor_[i]->getType());
			delete floor_[i];
		}
		delete[] floor_;
	}
}

const std::string&	Character::getName() const	{	return name_;	}

void	Character::equip(AMateria* m)	{
	for (std::size_t i = 0; i < ft::kSlotSize; ++i)	{
		if (slot_[i] == NULL)	{
			_PrintMsg("Equip item [" + _toString(static_cast<int>(i)) + "] ->", m->getType());
			slot_[i] = m;
			return ;
		}
	}
	_PrintMsg("Equip : full slot", name_);
}

void	Character::unequip(int idx)	{
	if (0 <= idx && idx < ft::kSlotSize)	{
		if (slot_[idx])	{
			_PrintMsg("Unequip item [" + _toString(idx) + "] ->", slot_[idx]->getType());
			_cleanUpFloor(this, idx);
			slot_[idx] = NULL;
		}
		else {
			_PrintMsg("Unequip: empty slot", name_);
		}
	}
	else {
		_PrintMsg("Use: out of Index - " + _toString(idx), name_);
	}
}

void	Character::use(int idx, ICharacter& target)	{
	if (0 <= idx && idx < ft::kSlotSize)	{
		if (slot_[idx])	{
			_PrintMsg("Use item [" + _toString(idx) + "] ->", slot_[idx]->getType());
			slot_[idx]->use(target);
		}
		else {
			_PrintMsg("Use: empty slot", name_);
		}
	}
	else {
		_PrintMsg("Use: out of Index - " + _toString(idx), name_);
	}
}

size_t	Character::getFloorCapacity() const	{	return floor_capacity_;	}
size_t	Character::getLeftCount() const	{	return left_count_;	}
void	Character::incLeftCount() const	{	left_count_ += 1;	}
void	Character::setFloorCapacity(std::size_t capacity)	{	floor_capacity_ = capacity;	}

void	Character::setFloor(std::size_t idx, AMateria* m) const {
	if (idx < floor_capacity_)	{
		floor_[idx] = m;
		incLeftCount();
	}
}

AMateria*	Character::getSlot(std::size_t idx) const	{
	if (idx < ft::kSlotSize)
		return slot_[idx];
	return NULL;
}

void	Character::newFloor()	{
	floor_ = new AMateria*[floor_capacity_];
}

void	Character::resizeFloor()	{
	AMateria** temp = floor_;

	setFloorCapacity(floor_capacity_ * 2);
	newFloor();
	for (std::size_t i = 0; i < left_count_; ++i)	{
		floor_[i] = temp[i];
	}
	delete[] temp;
}
