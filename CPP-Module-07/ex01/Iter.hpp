/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:50:03 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/22 21:38:23 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <cstddef>

template <class T>
void	iter(T* address, std::size_t lenght, void (*fn_p)(T&))	{
	for (std::size_t i = 0; i < lenght; ++i)	{
		fn_p(address[i]);
	}
}

template <class T>
void	iter(const T* address, std::size_t lenght, void (*fn_p)(const T&))	{
	for (std::size_t i = 0; i < lenght; ++i)	{
		fn_p(address[i]);
	}
}

#endif
