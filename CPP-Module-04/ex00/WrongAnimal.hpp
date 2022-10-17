/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:04:56 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:05:47 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONG_ANI_MAL__
# define __WRONG_ANI_MAL__

#include <string>

class WrongAnimal	{

	protected:
		std::string 		type_;

	public:
		WrongAnimal(const std::string& type = "init_meta");
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &from);
		WrongAnimal& operator=(const WrongAnimal& from);

		void				makeSound() const;
		const std::string&	getType() const;

};

#endif
