#pragma once

#ifndef __PMERGE_ME_HPP__
#define __PMERGE_ME_HPP__

#include <deque>
#include <iostream>
#include <vector>

#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <sys/time.h>

#include "util.hpp"

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

typedef enum sort_mode {
	fake_merge_insert,
	real_merge_insert
} sort_mode_e;

template <typename _Tp>
class PmergeMe {
public:
	typedef const PmergeMe& const_reference;
	typedef PmergeMe&		reference;
	typedef _Tp				container;

private:
	container	   data_;
	print_mode_e   mode_;
	struct timeval start_, end_;

	void
	get_time_(struct timeval& time) {
		gettimeofday(&time, NULL);
	}
	void print_(const char* msg = "Before ", const char* color = COLOR_RESET);
	void print_time_();

	void sort_fake_merge_insert_();
	void sort_real_merge_insert_();
	void fake_work_(size_t start, size_t end);
	void fake_merge_work_(size_t start, size_t middle, size_t end);
	void fake_insert_work_(size_t start, size_t end);

	void select_sort_(sort_mode_e sort_mode);

public:
	PmergeMe(container init = container(), print_mode_e print_mode = print_off, sort_mode_e sort_mode = fake_merge_insert);
	~PmergeMe();
	PmergeMe(const_reference from);
	reference operator=(const_reference from);
};

__TP__
__NS__::PmergeMe(__NS__::container init, print_mode_e print_mode, sort_mode_e sort_mode)
	: data_(init)
	, mode_(print_mode) {
	select_sort_(sort_mode);
}

__TP__ __NS__::~PmergeMe() { }

__TP__
__NS__::PmergeMe(__NS__::const_reference from) {
	*this = from;
}

__TP__
typename __NS__::reference
__NS__::operator=(__NS__::const_reference from) {
	if (this != &from) {
		data_ = from.data_;
		mode_ = from.mode_;
	}
	return *this;
}

__TP__
void
__NS__::select_sort_(sort_mode_e sort_mode) {
	if (mode_ == print_on) {
		print_();
	}
	get_time_(start_);
	if (sort_mode == fake_merge_insert) {
		sort_fake_merge_insert_();
	} else {
		sort_real_merge_insert_();
	}
	get_time_(end_);
	if (mode_ == print_on) {
#ifdef LOG
		if (std::is_sorted(data_.begin(), data_.end())) {
			print_("After", COLOR_GREEN);
		} else {
			print_("After", COLOR_RED);
		}
#else
		print_("After");
#endif
	}
	print_time_();
}

__TP__
void
__NS__::print_time_() {
	long seconds	  = end_.tv_sec - start_.tv_sec;
	long microseconds = end_.tv_usec - start_.tv_usec;
	if (microseconds < 0) {
		microseconds += 1e+6;
		seconds -= 1;
	}
	std::cout << "Time to process a range of 5 elements with std::[..] : ";
	std::cout << std::setw(3) << seconds * 1e+6 << ".";
	std::cout << std::setfill('0') << std::setw(6) << microseconds;
	std::cout << " us" << std::setfill(' ') << std::endl;
}

__TP__
void
__NS__::print_(const char* msg, const char* color) {
	size_t i = 1;

	std::cout << "\n"
			  << color << msg << std::endl;
	for (typename __NS__::container::iterator it = data_.begin();
		 it != data_.end();
		 ++it, ++i) {
		std::cout << std::setw(4) << *it << " ";
		if (i % 10 == 0) {
			std::cout << std::endl;
		}
	}
	std::cout << COLOR_RESET << std::endl;
}

__TP__
void
__NS__::sort_fake_merge_insert_() {
	fake_work_(0, data_.size());
}

__TP__
void
__NS__::fake_work_(size_t start, size_t end) {
	if (end - start > K_SIZE) {
		size_t middle = (start + end) / 2;
		fake_work_(start, middle);
		fake_work_(middle, end);
		fake_merge_work_(start, middle, end);
	} else {
		fake_insert_work_(start, end);
	}
}

__TP__
void
__NS__::fake_merge_work_(size_t start, size_t middle, size_t end) {
	size_t n1 = middle - start;
	size_t n2 = end - middle;

	container left(data_.begin() + start, data_.begin() + middle);
	container right(data_.begin() + middle, data_.begin() + end);

	size_t r_idx  = 0;
	size_t l_idx  = 0;
	size_t target = start + end - start;

	for (size_t i = start; i < target; ++i) {
		if (r_idx == n2) {
			data_[i] = left[l_idx];
			l_idx++;
		} else if (l_idx == n1) {
			data_[i] = right[r_idx];
			r_idx++;
		} else if (right[r_idx] > left[l_idx]) {
			data_[i] = left[l_idx];
			l_idx++;
		} else {
			data_[i] = right[r_idx];
			r_idx++;
		}
	}
}

__TP__
void
__NS__::fake_insert_work_(size_t start, size_t end) {
	for (size_t i = start; i < end - 1; i++) {
		size_t j	= i + 1;
		size_t temp = data_[j];

		for (; j > start && data_[j - 1] > temp; --j) {
			data_[j] = data_[j - 1];
		}
		data_[j] = temp;
	}
}

__TP__
void
__NS__::sort_real_merge_insert_() {
	real_work_(0, data_.size());
}

#undef __NS__
#undef __TP__

#endif
