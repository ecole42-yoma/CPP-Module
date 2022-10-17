/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:01:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:12:14 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef __D_O_G_HPP__
# define __D_O_G_HPP__

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Dog : public Animal	{

	private:
		Brain*				brain_;

	public:
		explicit Dog(std::string const& name = "Dog");
		Dog(const Dog &from);
		Dog& operator=(const Dog& from);
		virtual ~Dog();

		virtual	void		makeSound() const;
		void				setBrain(const std::size_t& index, const std::string& idea);
		std::string			getBrain(const std::size_t& index) const;
		void				printIdeas() const;

};

#endif

