/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:44:34 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:24:35 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ANI_MAL__
# define __ANI_MAL__

#include <string>

class Animal	{

	protected:
		std::string 		type_;

	public:
		explicit Animal(const std::string& type = "form_of_animal");
		virtual ~Animal();
		Animal(const Animal &from);
		Animal& operator=(const Animal& from);

		virtual void		makeSound() const;
		const std::string&	getType() const;

};

#endif
