/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:02:45 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:45:47 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AAnimal.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[Dog] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Dog::Dog(const std::string& type)
: AAnimal(type), brain_(new Brain(type))	{
	_PrintMsg("Default constructor called", type_);
}

Dog::~Dog()	{
	_PrintMsg("Destructor called", type_);
	delete brain_;
}

Dog::Dog(const Dog& from)
: AAnimal("Dog_Copy_Type"), brain_(NULL)	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

Dog& Dog::operator=(const Dog& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	AAnimal::operator=(operand);
	if (brain_)	{
		Brain* plate = brain_;
		delete plate;
	}
	brain_ = new Brain(*operand.brain_);
	return *this;
}

void	Dog::makeSound(void) const	{	_PrintMsg("Bark!", type_);	}

void	Dog::setBrain(const std::size_t& index, const std::string& idea)	{
	brain_->setIdea(index, idea);
}

std::string	Dog::getBrain(const std::size_t& index) const	{
	return brain_->getIdea(index);
}

void	Dog::printIdeas() const	{	brain_->printIdeas();	}
