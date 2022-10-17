/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:49:03 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/12 20:30:17 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
# define __FIXED_HPP__

class Fixed	{

	private:
		int					fixed_point_value_;
		static const int	kFractionalBits_;

	public:
		Fixed(void);
		explicit Fixed(const Fixed& from);
		Fixed&	operator=(const Fixed& operand);
		~Fixed(void);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

};

#endif /* __FIXED_HPP__ */
