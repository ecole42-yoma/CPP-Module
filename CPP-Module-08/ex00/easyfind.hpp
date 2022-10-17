/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:44:52 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/24 20:38:24 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

# include<algorithm>
# include<map>

template <class T>
typename T::iterator easyfind(T& container, int n)	{
	return std::find(container.begin(), container.end(), n);
}

template <class T>
typename T::const_iterator easyfind(const T& container, int n)	{
	return std::find(container.begin(), container.end(), n);
}

template <>
std::map<int, int>::iterator easyfind(std::map<int, int>& container, int n)	{
	// std::map<int, int>::iterator it = std::find(container.begin(), container.end(), n);
	return container.find(n);
}

template <>
std::map<int, int>::const_iterator easyfind(const std::map<int, int>& container, int n)	{
	return container.find(n);
}

# endif
