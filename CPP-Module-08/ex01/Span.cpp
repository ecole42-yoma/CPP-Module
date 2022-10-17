/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:52:25 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 10:26:33 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Span::Span(const unsigned int n)
: capacity_(n), recent_mody_indicator_short_(false), recent_mody_indicator_long_(false), shortest_(static_cast<int64_t>(INT_MAX)), longest_(0)	{
	if (capacity_ < 2)	{
		throw OutOfIndexException();
	}
}

Span::Span(const Span& from)
: set_(from.set_), capacity_(from.capacity_), recent_mody_indicator_short_(from.recent_mody_indicator_short_),
recent_mody_indicator_long_(from.recent_mody_indicator_long_), shortest_(from.shortest_), longest_(from.longest_) {
}

Span&	Span::operator=(const Span& operand)	{
	if (this != &operand)	{
		set_ = operand.set_;
		const_cast<unsigned int&>(capacity_) = operand.capacity_;
		recent_mody_indicator_short_ = operand.recent_mody_indicator_short_;
		recent_mody_indicator_long_ = operand.recent_mody_indicator_long_;
		shortest_ = operand.shortest_;
		longest_ = operand.longest_;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int n)	{
	if (set_.size() == capacity_)	{
		throw OutOfIndexException(OutOfIndexException::kOutOfRange);
	}
	else if (set_.find(n) != set_.end())	{
		std::cerr << set_.size()  << "] Overlap : " << n << " is already in set" << std::endl;
		throw OutOfIndexException(OutOfIndexException::kOverLap);
	}
	set_.insert(n);
	recent_mody_indicator_short_ = true;
	recent_mody_indicator_long_ = true;
}

void	Span::addNumberRepeat(int n)	{
	if (set_.size() == capacity_)	{
		throw OutOfIndexException(OutOfIndexException::kOutOfRange);
	}
	else if (set_.size() + n > capacity_)	{
		throw OutOfIndexException(OutOfIndexException::kInvalidRange);
	}
	std::srand(time(NULL));
	for (int i = 0; i < n; ++i)	{
		addNumber(rand() + i);
	}
	recent_mody_indicator_short_ = true;
	recent_mody_indicator_long_ = true;
}

int64_t	Span::shortestSpan()	{
	if (set_.size() < 2)	{
		throw OutOfIndexException(OutOfIndexException::kInvalidRange);
	}
	else if (recent_mody_indicator_short_)	{
		std::set<int>::iterator it	= set_.begin();

		while (it != set_.end())	{
			std::set<int>::iterator it2 = it;
			it2++;
			if (it2 != set_.end())	{
				int64_t temp = static_cast<int64_t>(*it2) - static_cast<int64_t>(*it);
				if (temp < 0)
					temp *= -1;
				if (shortest_ > temp)	{
					shortest_ = temp;
				}
			}
			it++;
		}
		recent_mody_indicator_short_ = false;
	}
	return shortest_;
}

int64_t	Span::longestSpan()	{
	if (set_.size() < 2)	{
		throw OutOfIndexException(OutOfIndexException::kInvalidRange);
	}
	else if (recent_mody_indicator_long_)	{
		int64_t temp = static_cast<int64_t>(*set_.rbegin()) - static_cast<int64_t>(*set_.begin());
		if (temp < 0)
			temp *= -1;
		longest_ = temp;
		recent_mody_indicator_long_ = false;
	}
	return longest_;
}

unsigned long	Span::getSize() const	{
	return set_.size();
}

void	Span::show() const	{
	std::set<int>::iterator it = set_.begin();
	unsigned int			line = 0;

	while (it != set_.end())	{
		std::cout << std::setw(13) << *it;
		++line;
		if (line % 10 == 0)	{
			std::cout << std::endl;
			line = 0;
		}
		it++;
	}
}

Span::OutOfIndexException::OutOfIndexException(const int& mode)
: mode_(mode) {}

const char* Span::OutOfIndexException::what() const throw()	{
	if (mode_ == kInvalidRange)	{
		return "Invalid Range";
	}
	else if (mode_ == kOutOfRange)	{
		return "Out of Range";
	}
	else if (mode_ == kOverLap)	{
		return "\033[0;31mOverLap\033[0m";
	}
	else	{
		return "Unknown Error";
	}
}
