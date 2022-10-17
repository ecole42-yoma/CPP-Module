/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:42:01 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:31:39 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>

namespace	{
	void	_PrintMsg(const std::string& msg)	{
		#ifdef LOG
			std::cout << "[Brain] " << msg << std::endl;
		#else
			(void)msg;
		#endif
	}

	std::string	_toString(std::size_t idx)	{
		std::stringstream ss;
		ss << idx;
		return ss.str();
	}
}

Brain::Brain(std::string const& neuron)	{
	_PrintMsg("Default constructor called");
	for (size_t i = 0; i < ft::kMaxNeuron; ++i)	{
		ideas_[i] = neuron + "'s neuron no." + _toString(i);
	}
}

Brain::Brain(const Brain& from)	{
	_PrintMsg("Copy constructor called");
	*this = from;
}

Brain&	Brain::operator=(const Brain& operand)	{
	_PrintMsg("Copy assignment operator called");
	for (std::size_t i = 0; i < ft::kMaxNeuron; ++i)
		ideas_[i] = operand.getIdea(i);
	return *this;
}

Brain::~Brain()	{	_PrintMsg("Destructor called");	}

std::string	Brain::getIdea(const std::size_t& index) const	{
	if (index < ft::kMaxNeuron)
		return ideas_[index];
	return "";
}

void	Brain::setIdea(const std::size_t& index, const std::string& idea)	{
	if (index < ft::kMaxNeuron)
		ideas_[index] = idea;
}

void Brain::printIdeas() const	{
	for (std::size_t i = 0; i < ft::kMaxNeuron; ++i)
		std::cout << ideas_[i] << std::endl;
}
