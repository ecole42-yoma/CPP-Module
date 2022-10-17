/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:31:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/08 07:25:00 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>

int main(int argc, char* argv[])	{
	if (!ft::Replace(argc, argv).Run())
		return 1;
	return 0;
}
