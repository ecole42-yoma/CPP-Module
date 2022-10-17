/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:49:10 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 11:12:12 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>

namespace	{

	void	_CheckError(int argc, char* argv[], int& error)	{
		error = 0;

		if (argc != ft::kValidArgc)	{
			std::cout << "Error: Check arguments" << std::endl;
			std::cout << "Usage: ./sed_is_for_losers [filename] [s1 - org] [s2 - replace]" << std::endl;
			error |= 1;
		}
		else if (!argv[ft::kFileName] || !argv[ft::kStrOri] || !argv[ft::kStrRep] )	{
			std::cout << "Error : Wrong arguments detected" << std::endl;
			error |= 1;
		}
        else if (std::strcmp(argv[ft::kStrOri], argv[ft::kStrRep]) == 0)    {
            std::cout << "Error: S1 == S2, nothing to be changed." << std::endl;
            error |= 1;
        }
	}

	void	_CheckEmpty(std::string const& filename, std::string const& s1, int& error )	{
		if (filename.empty() || s1.empty())	{
			std::cout << "Error : [filename] or [s1] can't be empty" << std::endl;
			error |= 1;
		}
	}

	void	_InitInfo(char* argv[], std::string& filename, std::string& org, std::string& rep )	{
		filename = argv[ft::kFileName];
		org = argv[ft::kStrOri];
		rep = argv[ft::kStrRep];

		std::cout << "[info]" << std::endl;
		std::cout << "filename : " << filename << std::endl;
		std::cout << "s1 - org : " << org << std::endl;
		std::cout << "s2 - rep : " << rep << std::endl;
		std::cout << std::endl;
	}

	void	_FileOpen(std::fstream& fs, std::string const& filename, std::ios_base::openmode const& mode, int& error)	{
		if (!error)	{
			fs.open(filename, mode);

			if (!fs)	{
				std::cout << "Error : Can't open file : " << filename << std::endl;
				error |= 1;
			}
		}
	}

	void	_ReplaceWork(std::string& str, std::string const& org, std::string const& rep )	{
		std::string::size_type	pos = 0;

		while ((pos = str.find(org, pos)) != std::string::npos)	{
			str.erase(pos, org.length());
			str.insert(pos, rep);
			pos += rep.length();
		}
	}

}	/* namespace */

ft::Replace::Replace(int argc, char* argv[])	{
	_CheckError(argc, argv, error_);
	if (!error_)	{
		_CheckEmpty(argv[kFileName], argv[kStrOri], error_);
	}

	if (!error_)	{
		_InitInfo(argv, file_name_, s1_, s2_);
		_FileOpen(file_[kReadOnly], file_name_, std::fstream::in, error_);
		_FileOpen(file_[kWriteOnly], file_name_ + kSuffix, std::fstream::out | std::fstream::trunc , error_);
	}

	if (!error_)	{
		ss_ << file_[kReadOnly].rdbuf();
        if (ss_.fail())
            error_ |= 1;
	}
}

ft::Replace::~Replace(void)	{
	if (file_[kReadOnly].is_open())	{
		std::cout << "Close [ read ] file" << std::endl;
		file_[kReadOnly].close();
	}
	if (file_[kWriteOnly].is_open())	{
		std::cout << "Close [ write ] file" << std::endl;
		file_[kWriteOnly].close();
	}

	if (!error_)	{
		std::cout << " [ Success ] " << std::endl;
	}
	else	{
		std::cout << " [ Failed ] " << std::endl;
	}
}

bool	ft::Replace::Run(void)	{
	if (error_)	{
		return false;
	}
	std::string output(ss_.str());
	_ReplaceWork(output, s1_, s2_);
	file_[kWriteOnly] << output;
	return true;
}
