/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 03:57:09 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/22 17:16:33 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>
#include <iomanip>
#include <sys/_types/_uintptr_t.h>

int main()	{
	Data	data = {
		"Hello World!",
		42,
		3.1415926535897,
		NULL,
		1
	};
	data.v_ptr = &data;

	std::cout << "Before serialize" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "data addr   -> " << &data << std::endl;
	std::cout << "data.c_arr   : " << data.c_arr << std::endl;
	std::cout << "data.i_num   : " << data.i_num << std::endl;
	std::cout << "data.d_num   : " << std::setprecision(14) << data.d_num << std::endl;
	std::cout << "data.v_ptr   : " << data.v_ptr << std::endl;
	std::cout << "data.i_num_2 : " << data.i_num_2 << std::endl;

	std::cout << "\n------------------" << std::endl;
	uintptr_t	serialized = serialize(&data);
	std::cout << "serialized addr       -> " << &serialized << std::endl;
	std::cout << "serialized value      -> " << serialized << std::endl;
	std::cout << "serialized value hex  -> " << std::hex << serialized << std::dec << std::endl;

	{
		std::cout << "\n------------------" << std::endl;
		Data*  final = deserialize(serialized);
		std::cout << "data* addr    -> " << &final << std::endl;
		std::cout << "data*         -> " << final << std::endl;
		std::cout << "final->c_arr   : " << final->c_arr << std::endl;
		std::cout << "final->i_num   : " << final->i_num << std::endl;
		std::cout << "final->d_num   : " << std::setprecision(14) << final->d_num << std::endl;
		std::cout << "final->v_ptr   : " << final->v_ptr << std::endl;
		std::cout << "final->i_num_2 : " << final->i_num_2 << std::endl;
	}
	{
		std::cout << "\n modi version ------------------" << std::endl;
		data.i_num_2 = 111;
		uintptr_t	se2	= serialize(&data);
		std::cout << "serialized addr       -> " << &se2 << std::endl;
		std::cout << "serialized value      -> " << se2 << std::endl;
		std::cout << "serialized value hex  -> " << std::hex << se2 << std::dec << std::endl;

		std::cout << "------------------" << std::endl;
		Data*  final = deserialize(se2);
		std::cout << "data* addr    -> " << &final << std::endl;
		std::cout << "data*         -> " << final << std::endl;
		std::cout << "final->c_arr   : " << final->c_arr << std::endl;
		std::cout << "final->i_num   : " << final->i_num << std::endl;
		std::cout << "final->d_num   : " << std::setprecision(14) << final->d_num << std::endl;
		std::cout << "final->v_ptr   : " << final->v_ptr << std::endl;
		std::cout << "final->i_num_2 : " << final->i_num_2 << std::endl;
	}

	return 0;
}
