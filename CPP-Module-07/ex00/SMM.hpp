/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SMM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:08:50 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 08:57:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__SMM_HPP__
# define	__SMM_HPP__

#include <iostream>
#include <string>

template <class T>
void	swap(T& a, T& b)	{
	if (a != b)	{
		T temp;

		temp = a;
		a = b;
		b = temp;
	}
}

template <class T>
void	swap(T const& a, T const& b)	{
	if (a != b)	{
		throw std::string("const swap not supported");
	}
}

template <class T>
T&	min(T& a, T& b)	{
	if (a < b)
		return a;
	return b;
}

template <class T>
const T&	min(T const& a, T const& b)	{
	if (a < b)
		return a;
	return b;
}

template <class T>
T&	max(T& a, T& b)	{
	if (a > b)
		return a;
	return b;
}

template <class T>
const T&	max(T const& a, T const& b)	{
	if (a > b)
		return a;
	return b;
}


#endif
