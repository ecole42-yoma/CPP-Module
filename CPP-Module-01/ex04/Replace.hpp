/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:26:56 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 17:22:30 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __REPLACE_HPP__
# define __REPLACE_HPP__

# include <fstream>
# include <sstream>
# include <string>

// # define SUFFIX ".replace"
// # define VAILD_ARGC 4
// constexpr std::string SUFFIX = ".replace";
// constexpr int VALID_ARGC = 4;

namespace ft	{

	const int			kValidArgc = 4;
	const std::string	kSuffix = ".replace";

	enum FileType	{
		kReadOnly,
		kWriteOnly
	};

	enum Argument	{
		kFileName = 1,
		kStrOri,
		kStrRep
	};

	class Replace	{

		private:
			std::string			file_name_;
			std::string			s1_;
			std::string			s2_;
			std::stringstream	ss_;
			std::fstream		file_[2];
			int					error_;

		public:
			Replace(int argc, char* argv[]);
			~Replace(void);
			bool			Run(void) ;

	}; /* class Replace end */

}/* namespace ft end */

#endif /* __REPLACE_HPP__ */
