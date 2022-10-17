/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:28:37 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 17:53:17 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MATERIASOURCE__HPP__
# define __MATERIASOURCE__HPP__

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include <string>

namespace IMS	{
	enum Info	{
		kSlotSize = 4
	};
}

class MateriaSource : public IMateriaSource	{

	private:
		AMateria*		learned_[IMS::kSlotSize];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& from);
		MateriaSource& operator=(MateriaSource const& operand);
		virtual ~MateriaSource();

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const& type);

};

#endif
