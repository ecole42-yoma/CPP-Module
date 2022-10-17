/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:22:06 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/12 20:30:27 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>

class Fixed	{

	private:
		int 				fixed_point_value_;
		static const int	kFractionalBits_;


	public:
		Fixed(void);
		~Fixed(void);
		explicit Fixed(const int& value);
		explicit Fixed(const float& value);
		Fixed(const Fixed& from);
		Fixed& operator=(const Fixed& operand);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;


};

std::ostream& operator<<(std::ostream& __out, const Fixed& fixed);

#endif /* __FIXED_HPP__ */
