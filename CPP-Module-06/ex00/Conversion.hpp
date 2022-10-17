/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:44:45 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/22 17:29:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONVERSION_HPP__
# define __CONVERSION_HPP__

# include <string>

class Conversion	{

	private:

		enum Size	{
			kCapa = 4
		};


		char const*			input_;
		long				int_;
		double				double_;
		char const*			func_name_[kCapa];
		void				(Conversion::*fp_[kCapa])() const;
		bool				inf_nan_indicator_;

		void				_charConv() const;
		void				_intConv() const;
		void				_floatConv() const;
		void				_doubleConv() const;

	public:
		explicit Conversion(char const* input = "0");
		~Conversion();
		Conversion(Conversion const& from);
		Conversion& operator=(Conversion const& operand);

		void				print(std::string const& type);


};

#endif

// strtod strtol strtof
// isnormal isfinite isinf isnan

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

*/
