/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:44:34 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 23:32:29 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AANI_MAL_HPP__
# define __AANI_MAL_HPP__

#include <string>

class AAnimal	{

	protected:
		std::string 		type_;

	public:
		explicit AAnimal(const std::string& type = "form_of_animal");
		virtual ~AAnimal();
		AAnimal(const AAnimal &from);
		AAnimal& operator=(const AAnimal& from);

		virtual void		makeSound() const = 0;
		const std::string&	getType() const;

};

#endif
