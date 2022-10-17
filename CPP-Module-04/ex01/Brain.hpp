/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:37:01 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:10:31 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>

namespace ft	{

	enum BrainSize	{
		kMaxNeuron = 100
	};
}

class Brain	{

	private:
		std::string		ideas_[ft::kMaxNeuron];

	public:
		explicit Brain(std::string const& neuron = "neuron");
		Brain(const Brain& from);
		Brain&	operator=(const Brain& operand);
		~Brain();

		std::string		getIdea(const std::size_t& index) const;
		void			setIdea(const std::size_t& index, const std::string& idea);
		void			printIdeas() const;

};

#endif
