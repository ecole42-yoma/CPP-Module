/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:17:11 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 17:57:27 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	__ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Ice : public AMateria	{

	public:
		explicit Ice(std::string const& type = "ice");
		Ice(Ice const& from);
		Ice&	operator=(Ice const& operand);
		virtual ~Ice();

		virtual	AMateria*		clone() const;
		virtual void 			use(ICharacter& target);
};

#endif
