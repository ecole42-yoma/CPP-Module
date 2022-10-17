/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:22:06 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/12 20:48:29 by yongmkim         ###   ########seoul.kr  */
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
		bool operator>(const Fixed& operand) const;
		bool operator<(const Fixed& operand) const;
		bool operator>=(const Fixed& operand) const;
		bool operator<=(const Fixed& operand) const;
		bool operator==(const Fixed& operand) const;
		bool operator!=(const Fixed& operand) const;
		Fixed operator+(const Fixed& operand) const;
		Fixed operator-(const Fixed& operand) const;
		Fixed operator*(const Fixed& operand) const;
		Fixed operator/(const Fixed& operand) const;
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);


		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(Fixed const& a, Fixed const& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(Fixed const& a, Fixed const& b);

};

std::ostream& operator<<(std::ostream& __out, const Fixed& fixed);

#endif /* __FIXED_HPP__ */
