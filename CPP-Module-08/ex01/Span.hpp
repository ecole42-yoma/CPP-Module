/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:44:09 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 10:09:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <cstddef>
#include <exception>
#include <set>
#include <cstdint>

class Span	{
	private:
		std::set< int >		set_;
		const unsigned int	capacity_;
		bool				recent_mody_indicator_short_;
		bool				recent_mody_indicator_long_;
		int64_t				shortest_;
		int64_t				longest_;

	public:
		explicit Span(const unsigned int n = 0);
		Span(const Span& from);
		Span& operator=(const Span& operand);
		~Span();

		void			addNumber(int n);
		void			addNumberRepeat(int n);
		int64_t			shortestSpan();
		int64_t			longestSpan();
		unsigned long	getSize() const;
		void			show() const;

		class OutOfIndexException : public std::exception {
			private:
				int		mode_;

			public:
				enum ErrorType{
					kInvalidRange,
					kOutOfRange,
					kOverLap
				};
				explicit OutOfIndexException(const int& mode = kInvalidRange);
				virtual const char* what() const throw();
		};

};

#endif
