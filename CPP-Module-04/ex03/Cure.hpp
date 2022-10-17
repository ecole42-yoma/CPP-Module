/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:39:41 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 17:56:53 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	__CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Cure : public AMateria	{

	public:
		explicit Cure(std::string const& type = "cure");
		Cure(Cure const& from);
		Cure&	operator=(Cure const& operand);
		virtual ~Cure();

		virtual	AMateria*		clone() const;
		virtual void 			use(ICharacter& target);
};

#endif
