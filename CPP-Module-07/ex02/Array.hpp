/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:50:39 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 10:35:38 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__ARRAY_HPP__
# define	__ARRAY_HPP__

# include <exception>

template <class T>
class Array	{

	private:
		unsigned int	length_;
		T*				array_;

	public:
		Array();
		~Array();
		explicit Array(const unsigned int n);
		explicit Array(Array const& from);
		Array<T>& operator=(Array const& operand);
		T& operator[](const std::size_t idx);
		const T& operator[](const std::size_t idx) const;

		std::size_t		size() const;


		class	IndexException:	public std::exception	{
			virtual const char* what() const throw();
		};
};

# include "Array.tpp"

#endif
