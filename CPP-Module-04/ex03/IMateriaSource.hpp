/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:22:05 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/16 17:42:52 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __IMATERIASOURCE__HPP__
# define __IMATERIASOURCE__HPP__

# include <string>

class AMateria;

class IMateriaSource	{

	public:
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const& type) = 0;

};

#endif
