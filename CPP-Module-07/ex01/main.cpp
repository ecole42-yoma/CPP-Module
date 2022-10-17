/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:57:14 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/23 04:03:54 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
#include <iomanip>

template <class T>
void	_printUp(T& a)	{
	std::cout << std::setw(5) << a + 32;
}

template <class T>
void	_printUp(const T& a)	{
	std::cout << std::setw(5) << a + 32;
}

template <>
void	_printUp<char>(char& a)	{
	std::cout << std::setw(5) << static_cast<char>(a + 32);
}

template <>
void	_printUp<char>(char const& a)	{
	std::cout << std::setw(5) << static_cast<char>(a + 32);
}

int main()	{
	{
		std::cout << " abc array" << std::endl;
		char	abc[26];

		for (std::size_t i = 0; i < 26; ++i)	{
			abc[i] = 'A' + i;
			std::cout << std::setw(5) << abc[i];
		}
		std::cout << std::endl;

		iter(abc, sizeof(abc) / sizeof(*abc), _printUp);
		std::cout << std::endl;
	}

	try
	{
		std::cout << "\n const abc array" << std::endl;
		const char	abc[] = {'A', 'B', 'C', 'D', 'E'};

		for (std::size_t i = 0; i < 5; ++i)	{
			std::cout << std::setw(5) << abc[i];
		}
		std::cout << std::endl;

		iter(abc, sizeof(abc) / sizeof(*abc), _printUp);
		std::cout << std::endl;
	} catch	(std::string const& e){
		std::cerr << e << std::endl;
	}

	{
		std::cout << "\n number array" << std::endl;
		std::size_t	ten[10];

		for (std::size_t i = 0; i < 10; ++i)	{
			ten[i] = i;
			std::cout << std::setw(5) << ten[i];
		}
		std::cout << std::endl;

		iter(ten, sizeof(ten) / sizeof(*ten), _printUp);
		std::cout << std::endl;

	}

	{
		std::cout << "\n const number array" << std::endl;
		const std::size_t	ten[] = {0, 1, 2, 3, 4};

		for (std::size_t i = 0; i < 5; ++i)	{
			std::cout << std::setw(5) << ten[i];
		}
		std::cout << std::endl;

		iter(ten, sizeof(ten) / sizeof(*ten), _printUp);
		std::cout << std::endl;

	}

	{
		std::cout << "\n double number array" << std::endl;
		double	ten[10];

		for (std::size_t i = 0; i < 10; ++i)	{
			ten[i] = i;
			std::cout << std::setw(5) << std::fixed << std::setprecision(1) << ten[i];
		}
		std::cout << std::endl;

		iter(ten, sizeof(ten) / sizeof(*ten), _printUp);
		std::cout << std::endl;

	}

	{
		std::cout << "\n const double number array" << std::endl;
		const double	ten[] = {0, 1, 2, 3, 4};

		for (std::size_t i = 0; i < 5; ++i)	{
			std::cout << std::setw(5) << std::fixed << std::setprecision(1) << ten[i];
		}
		std::cout << std::endl;

		iter(ten, sizeof(ten) / sizeof(*ten), _printUp);
		std::cout << std::endl;

	}

	return 0;
}
