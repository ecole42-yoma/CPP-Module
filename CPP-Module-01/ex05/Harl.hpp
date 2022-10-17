/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:34:48 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:09:44 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __HARL_HPP__
# define __HARL_HPP__

# include <string>

namespace ft	{

	const std::string kDebugMsg = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!";
	const std::string kInfoMsg = "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!";
	const std::string kWarningMsg = "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.";
	const std::string kErrorMsg = "This is unacceptable! I want to speak to the manager now.";
	const std::string kOtherMsg = "Probably complaining about insignificant problems";

	enum Level	{
		kDebug,
		kInfo,
		kWarning,
		kError,
		kLevel,
		kSize
	};

	class Harl	{

		private:
			void		(ft::Harl::*fp_[kSize])(void) const;
			std::string	id_[kSize];

			void		debug(void) const;
			void		info(void) const;
			void		warning(void) const;
			void		error(void) const;
			void		other(void) const;


		public:
			Harl(void);
			void		complain(std::string const& level) const;

	}; /* class Harl end */

} /* namespace ft end */

#endif /* __HARL_HPP__ */
