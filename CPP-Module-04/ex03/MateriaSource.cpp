/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:36:04 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 21:43:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg)	{
		#ifdef LOG
			std::cout << "[\033[1;34mMateriaSource\033[0m] " << msg << std::endl;
		#else
			(void)msg;
		#endif
	}
}

MateriaSource::MateriaSource()	{
	_PrintMsg("Default constructor called");
	for (std::size_t i = 0; i < IMS::kSlotSize; i++)	{
		learned_[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const& from)	{
	_PrintMsg("Copy constructor called");
	for (std::size_t i = 0; i < IMS::kSlotSize; i++)	{
		learned_[i] = NULL;
	}
	*this = from;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& operand)	{
	_PrintMsg("Copy assignment operator called");
	{
		MateriaSource temp;

		for (std::size_t i = 0; i < IMS::kSlotSize; ++i)	{
			AMateria *m = learned_[i];
			learned_[i] = temp.learned_[i];
			temp.learned_[i] = m;
		}
	}
	for (std::size_t i = 0; i < IMS::kSlotSize; i++)	{
		if (operand.learned_[i])	{
			learned_[i] = operand.learned_[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()	{
	_PrintMsg("Destructor called");
	for (std::size_t i = 0; i < IMS::kSlotSize; i++)	{
		if (learned_[i])	{
			delete learned_[i];
		}
	}
}


void	MateriaSource::learnMateria(AMateria* m)	{
	for (std::size_t i = 0; i < IMS::kSlotSize; i++)	{
		if (learned_[i] == NULL)	{
			_PrintMsg("Learn Materia -> " + m->getType());
			learned_[i] = m;
			return ;
		}
	}
	_PrintMsg("Learn Materia : is full");
}

AMateria*	MateriaSource::createMateria(std::string const& type)	{
	for (std::size_t i = 0; i < IMS::kSlotSize; i++)	{
		if (learned_[i] && learned_[i]->getType() == type)	{
			_PrintMsg("Create Materia -> " + learned_[i]->getType());
			return learned_[i]->clone();
		}
	}
	_PrintMsg("Create Materia [ no matched ]-> " + type);
	return NULL;
}


