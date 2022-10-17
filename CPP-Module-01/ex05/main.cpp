/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:42:01 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/08 07:57:49 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main (int argc, char* argv[])	{

	if (argc != 2)	{
		std::cout << "Usage: ./harl [ DEBUG | INFO | WARNING | ERROR | ... ]" << std::endl;
		return 1 ;
	}
	ft::Harl().complain(argv[1]);
	return 0;
}
