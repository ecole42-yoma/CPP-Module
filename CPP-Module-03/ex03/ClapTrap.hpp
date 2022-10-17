/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:40:05 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/14 19:42:39 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAP_TRAP__
# define __CLAP_TRAP__

# include <string>

class ClapTrap	{

	private:
		std::string			name_;
		int					health_;
		int					energy_;
		int					damage_;

		static const int	kInitHealth = 10;
		static const int	kInitEnergy = 10;
		static const int	kInitDamage = 2;

	protected:
		void				_setName(const std::string& name = "Clap");
		void				_setHealth(int scalar = kInitHealth);
		void				_setEnergy(int scalar = -1);
		void				_setDamage(int scalar = kInitDamage);

	public:
		ClapTrap(std::string const& name	= "Clap_Init_Name",
					const int& hit_point	= 10,
					const int& energy_point	= 10,
					const int& attack_point	= 2);
		virtual ~ClapTrap(void);
		ClapTrap(ClapTrap const& from);
		ClapTrap& operator=(ClapTrap const& operand);

		virtual void		attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		int					getDamage(void)	const;
		int					getHealth(void)	const;
		int					getEnergy(void)	const;
		virtual std::string	getName(void)	const;

};

#endif /* __CLAP_TRAP_ */
