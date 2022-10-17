/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:44:32 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:08:29 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

namespace	{

	void	_Print(std::string const& msg)	{
		std::cout << msg << std::endl;
	}

} /* namespace end */

ft::Harl::Harl(void)	{
	{
		std::string	id[kSize] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR",
			kOtherMsg
		};

		for (int i = 0; i < kSize; i++)	{
			id_[i] = id[i];
		}
	}
	{
		void	(ft::Harl::*fp[kSize])(void) const = {
			&ft::Harl::debug,
			&ft::Harl::info,
			&ft::Harl::warning,
			&ft::Harl::error,
			&ft::Harl::other
		};

		for (int i = 0 ; i < kSize ; i++)	{
			fp_[i] = fp[i];
		}
	}
}

void	ft::Harl::debug(void) const		{	_Print( kDebugMsg );	}
void	ft::Harl::info(void) const		{	_Print( kInfoMsg );		}
void	ft::Harl::warning(void) const	{	_Print( kWarningMsg );	}
void	ft::Harl::error(void) const		{	_Print( kErrorMsg );	}
void	ft::Harl::other(void) const		{	_Print( kOtherMsg );	}

void	ft::Harl::complain(std::string const& level) const	{
	std::string::size_type	what_harl_say = 0;

	while (what_harl_say < static_cast<size_t>(kLevel))	{
		if (level == id_[what_harl_say]) {
			break ;
		}
		what_harl_say++;
	}
	(this->*fp_[what_harl_say])();
}
