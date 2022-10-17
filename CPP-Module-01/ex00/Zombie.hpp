/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:35:14 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:46:01 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <string>

namespace ft	{

	class Zombie	{

		private:
			std::string	name_;

		public:
			Zombie(void);
			explicit Zombie(const std::string& name);
			~Zombie(void);
			void	announce(void) const;

	}; /* class Zombie end */

	Zombie*	newZombie(std::string const& name);
	void	randomChump(std::string const& name);

}	/* namespace cpp end */

#endif /* __ZOMBIE_HPP__ */
