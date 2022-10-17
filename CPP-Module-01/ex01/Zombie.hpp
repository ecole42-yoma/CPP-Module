/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:35:14 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:40:52 by yongmkim         ###   ########seoul.kr  */
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
			static int	count_;


		public:
			Zombie(void);
			~Zombie(void);
			void	announce(void) const;
			void	initialize(std::string const& name, int id);
			static int		GetCount(void);

	};	/* class Zombie end */

	Zombie*	zombieHorde(int N, std::string const& name);

}/* namespace cpp end */

#endif /* __ZOMBIE_HPP__ */
