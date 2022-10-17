/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:07:54 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:15:06 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef __WRONG_C_A_T__
# define __WRONG_C_A_T__

# include "WrongAnimal.hpp"
# include <string>

class WrongCat : public WrongAnimal	{

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &from);
		WrongCat& operator=(const WrongCat& from);

		void		makeSound() const;

};

#endif
