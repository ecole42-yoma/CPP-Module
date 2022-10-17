/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:59:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:37:52 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include <iostream>

namespace	{
	void	_PrintMsg(const std::string& msg, const std::string& name)	{
		#ifdef LOG
			std::cout << "[Cat] " << msg << " [" << name << "]" << std::endl;
		#else
			(void)msg;
			(void)name;
		#endif
	}
}

Cat::Cat(const std::string& type)
: AAnimal(type), brain_(new Brain(type))	{
	_PrintMsg("Default constructor called", type_);
}

Cat::~Cat()	{
	_PrintMsg("Destructor called", type_);
	delete brain_;
}

Cat::Cat(const Cat& from)
: AAnimal("Cat_Copy_Type"), brain_(NULL)	{
	_PrintMsg("Copy constructor called", type_);
	*this = from;
}

Cat& Cat::operator=(const Cat& operand)	{
	_PrintMsg("Copy assignment operator called", type_);
	AAnimal::operator=(operand);
	if (brain_)	{
		Brain* plate = brain_;
		delete plate;
	}
	brain_ = new Brain(*operand.brain_);
	return *this;
}

void	Cat::makeSound(void) const	{	_PrintMsg("Meow~", type_);	}

void	Cat::setBrain(const std::size_t& index, const std::string& idea)	{
	brain_->setIdea(index, idea);
}

std::string	Cat::getBrain(const std::size_t& index) const	{
	return brain_->getIdea(index);
}

void	Cat::printIdeas() const	{	brain_->printIdeas();	}
