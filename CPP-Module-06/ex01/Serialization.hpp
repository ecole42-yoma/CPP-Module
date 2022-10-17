/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 03:53:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/22 17:07:20 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZATION_HPP__
# define __SERIALIZATION_HPP__

# include <cstdint>
# include <string>

struct Data	{
	char	c_arr[42];
	int		i_num;
	double	d_num;
	void*	v_ptr;
	int		i_num_2;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
