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

	void print_after_();

	void sort_();
	void sort_work_(size_t start, size_t end);
	void merge_work_(size_t start, size_t middle, size_t end);
	void insert_work_(size_t start, size_t end);

public:
	PmergeMe(container init = container(), print_mode_e mode = print_off);
	~PmergeMe();
	PmergeMe(const_reference from);
	reference operator=(const_reference from);
};

__TP__
__NS__::PmergeMe(__NS__::container init, print_mode_e mode)
	: data_(init)
	, mode_(mode) {
	sort_();
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
		data_ = from.data_;
		mode_ = from.mode_;
	}
	return *this;
}

__TP__
void
__NS__::print_after_() {
	std::cout << "After:" << std::setw(5);
	size_t i = 1;
	for (typename __NS__::container::iterator it = data_.begin();
		 it != data_.end();
		 ++it, ++i) {
		std::cout << std::setw(4) << *it << " ";
		if (i % 10 == 0) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

__TP__
void
__NS__::sort_() {

	struct timeval start, end;
	gettimeofday(&start, NULL);

	sort_work_(0, data_.size());

	gettimeofday(&end, NULL);

	if (mode_ == print_on) {
		print_after_();
	}
	long seconds	  = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
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
__NS__::sort_work_(size_t start, size_t end) {
	if (end - start > K_SIZE) {
		size_t middle = (start + end) / 2;
		sort_work_(start, middle);
		sort_work_(middle, end);
		merge_work_(start, middle, end);
	} else {
		insert_work_(start, end);
	}
}

__TP__
void
__NS__::merge_work_(size_t start, size_t middle, size_t end) {
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
__NS__::insert_work_(size_t start, size_t end) {
	for (size_t i = start; i < end - 1; i++) {
		size_t temp = data_[i + 1];
		size_t j	= i + 1;

		while (j > start && data_[j - 1] > temp) {
			data_[j] = data_[j - 1];
			j--;
		}
		data_[j] = temp;
	}
}

#undef __NS__
#undef __TP__

#endif
