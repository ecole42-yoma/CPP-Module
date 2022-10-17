/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:00:04 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 09:10:53 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
#include <iomanip>

template <class T>
void	_printUp(T& a)	{
	std::cout << std::setw(4) << a + 32;
}

template <class T>
void	_printUp(const T& a)	{
	std::cout << std::setw(4) << a + 32;
}

template <>
void	_printUp<char>(char& a)	{
	std::cout << std::setw(4) << static_cast<char>(a + 32);
}

template <>
void	_printUp<char>(char const& a)	{
	std::cout << std::setw(4) << static_cast<char>(a + 32);
}



template <class T>
void	iter(Array<T>& a, void (*func_ptr)(T&))	{
	for (std::size_t i = 0; i < a.size(); ++i)	{
		func_ptr(a[i]);
	}
}

template <class T>
void	iter(Array<T> const& a, void (*func_ptr)(T const&))	{
	for (std::size_t i = 0; i < a.size(); ++i)	{
		func_ptr(a[i]);
	}
}

template <class T>
void	iter(T* a, void (*func_ptr)(T&), std::size_t idx)	{
	for (std::size_t i = 0; i < idx; ++i)	{
		func_ptr(a[i]);
	}
}

template <class T>
void	iter(const T* a, void (*func_ptr)(T const&), std::size_t idx)	{
	for (std::size_t i = 0; i < idx; ++i)	{
		func_ptr(a[i]);
	}
}



int main_char()	{
	{
		std::cout << " abc array" << std::endl;
		Array<char>	abc_t_array(26);
		char		abc_char[26];

		std::cout << " Template array" << std::endl;
		for (std::size_t i = 0; i < 26; ++i)	{
			abc_t_array[i] = 'A' + i;
			std::cout << std::setw(4) << abc_t_array[i];
		}
		std::cout << std::endl;

		std::cout << "\n char array" << std::endl;
		for (std::size_t i = 0; i < 26; ++i)	{
			abc_char[i] = 'Z' - i;
			std::cout << std::setw(4) << abc_char[i];
		}
		std::cout << std::endl;

		std::cout << "\n Template array" << std::endl;
		iter(abc_t_array, _printUp);
		std::cout << "\n char array" << std::endl;
		iter(abc_char, _printUp, 26);
		std::cout << std::endl;

		std::cout << "\n\n\n\n[const] abc array" << std::endl;
		const Array<char>	abc_t_array_const(abc_t_array);
		const char			abc_char_const[3] = { 'Z', 'Y', 'X'	};

		std::cout << " Template array" << std::endl;
		for (std::size_t i = 0; i < 26; ++i)	{
			std::cout << std::setw(4) << abc_t_array_const[i];
		}
		std::cout << std::endl;

		std::cout << "\n char array" << std::endl;
		for (std::size_t i = 0; i < 3; ++i)	{
			std::cout << std::setw(4) << abc_char_const[i];
		}
		std::cout << std::endl;

		std::cout << "\n Template array" << std::endl;
		iter(abc_t_array_const, _printUp);
		std::cout << "\n char array" << std::endl;
		iter(abc_char_const, _printUp, 3);
		std::cout << std::endl;
		std::cout << std::endl;

		try {
			std::cout << "\n Template array error check" << std::endl;
			abc_t_array[26] = 'F';
		} catch (std::exception& e)	{
			std::cerr << e.what() << std::endl;
		}
	}


	return 0;
}

int main_int()	{
		std::cout << "\n\n\n\n number array" << std::endl;
		Array<int>	abc_t_array(10);
		int			abc_char[10];

		std::cout << " Template array" << std::endl;
		for (std::size_t i = 0; i < 10; ++i)	{
			abc_t_array[i] = i;
			std::cout << std::setw(4) << abc_t_array[i];
		}
		std::cout << std::endl;

		std::cout << "\n int array" << std::endl;
		for (std::size_t i = 0; i < 10; ++i)	{
			abc_char[i] = i;
			std::cout << std::setw(4) << abc_char[i];
		}
		std::cout << std::endl;

		std::cout << "\n Template array" << std::endl;
		iter(abc_t_array, _printUp);
		std::cout << "\n int array" << std::endl;
		iter(abc_char, _printUp, 10);
		std::cout << std::endl;


		std::cout << "\n\n[const] number array" << std::endl;
		const Array<int>	abc_t_array_const(abc_t_array);
		const int			abc_char_const[3] = { 10, 11, 12 };

		std::cout << " Template array" << std::endl;
		for (std::size_t i = 0; i < 10; ++i)	{
			std::cout << std::setw(4) << abc_t_array_const[i];
		}
		std::cout << std::endl;

		std::cout << "\n int array" << std::endl;
		for (std::size_t i = 0; i < 3; ++i)	{
			std::cout << std::setw(4) << abc_char_const[i];
		}
		std::cout << std::endl;

		std::cout << "\n Template array" << std::endl;
		iter(abc_t_array_const, _printUp);
		std::cout << "\n int array" << std::endl;
		iter(abc_char_const, _printUp, 3);
		std::cout << std::endl;
		std::cout << std::endl;


	return 0;
}

int main()	{
	main_char();
	std::cin.get();
	main_int();
	std::cout << "check leaks" << std::endl;
	std::cin.get();
	return 0;
}
