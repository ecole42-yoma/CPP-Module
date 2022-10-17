/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:55:51 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:13:00 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef __C_A_T_HPP__
# define __C_A_T_HPP__

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Cat : public Animal	{

	private:
		Brain*				brain_;

	public:
		explicit Cat(std::string const& name = "Cat");
		Cat(const Cat &from);
		Cat& operator=(const Cat& from);
		virtual ~Cat();

		virtual	void		makeSound() const;
		void				setBrain(const std::size_t& index, const std::string& idea);
		std::string			getBrain(const std::size_t& index) const;
		void				printIdeas() const;

};

#endif
