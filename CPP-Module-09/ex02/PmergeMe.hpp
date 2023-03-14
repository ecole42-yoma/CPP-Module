#pragma once

#ifndef __PMERGE_ME_HPP__
#define __PMERGE_ME_HPP__

#include <deque>
#include <iostream>
#include <vector>

#include <cstddef>
#include <ctime>

#ifndef K_SIZE
#define K_SIZE 5
#endif

#define __NS__ PmergeMe<_Tp>
#define __TP__ template <typename _Tp>

typedef std::vector<size_t> posi_vector;
typedef std::deque<size_t>	posi_deque;

typedef enum print_mode {
	print_on,
	print_off
} print_mode_e;

template <typename _Tp>
class PmergeMe {
public:
	typedef const PmergeMe& const_reference;
	typedef PmergeMe&		reference;
	typedef _Tp				container;
	// typedef container::value_type value_type;

private:
	container	 data_;
	print_mode_e mode_;
	std::time_t	 start_;
	std::time_t	 end_;

	void print_after_();
	void print_time_();

public:
	PmergeMe(container init = container(), print_mode_e mode = print_off);
	~PmergeMe();
	PmergeMe(const_reference from);
	reference operator=(const_reference from);
};

namespace {

} // namespace

__TP__
__NS__::PmergeMe(__NS__::container init, print_mode_e mode)
	: data_(init)
	, mode_(mode)
	, start_(0)
	, end_(0) {

	// start sort
	// set start time
	// sort
	// set end time
	// print result

	if (mode_ == print_on) {
		print_after_();
	}
}

__TP__
__NS__::~PmergeMe() { }

__TP__
__NS__::PmergeMe(__NS__::const_reference from) {
	*this = from;
}

__TP__
typename __NS__::reference
__NS__::operator=(__NS__::const_reference from) {
	if (this != &from) {
		data_  = from.data_;
		mode_  = from.mode_;
		start_ = from.start_;
		end_   = from.end_;
	}
	return *this;
}

__TP__
void
__NS__::print_after_() {
	std::cout << "After: \t";
	for (typename __NS__::container::iterator it = data_.begin();
		 it != data_.end();
		 ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

__TP__
void
__NS__::print_time_() {
	std::cout << "Time to process a range of 5 elements with std::[..] : ";
	std::cout << end_ - start_;
	std::cout << " us" << std::endl; // TODO: form 64.01202 us
}

#undef __NS__
#undef __TP__

#endif
