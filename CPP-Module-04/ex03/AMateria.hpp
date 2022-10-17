/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:16:47 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 17:57:19 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AMATERIA__HPP__
# define __AMATERIA__HPP__

# include "ICharacter.hpp"
# include <string>

class AMateria	{

	protected:
		std::string				type_;

	public:
		explicit AMateria(std::string const& type = "AMateria_Name");
		AMateria(AMateria const& from);
		AMateria&	operator=(AMateria const& operand);
		virtual ~AMateria();

		const std::string&		getType() const;
		virtual	AMateria*		clone() const = 0;
		virtual void 			use(ICharacter& target);

};

#endif
