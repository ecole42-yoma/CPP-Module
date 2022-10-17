/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:08:12 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 10:37:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_TPP__
# define __ARRAY_TPP__

template <class T>
Array<T>::Array()
: length_(0), array_(NULL)	{
}

template <class T>
Array<T>::~Array()	{
	if (array_)	{
		delete[] array_;
		array_ = NULL;
	}
}

template <class T>
Array<T>::Array(const unsigned int n)
: length_(n), array_(new T[length_]) {

}

template <class T>
Array<T>::Array(Array const& from)
: length_(from.length_), array_(NULL) {
	*this = from;
}

template <class T>
Array<T>& Array<T>::operator=(Array const& operand)	{

	if (this != &operand)	{
		if (array_)	{
			delete[] array_;
			array_ = NULL;
		}
		length_	= operand.length_;
		array_	= new T[length_];
		for (std::size_t i = 0; i < length_; ++i)	{
			array_[i] = operand.array_[i];
		}
	}
	return *this;
}

template <class T>
T& Array<T>::operator[](const std::size_t idx)	{
	if (idx >= length_)	{
		throw Array<T>::IndexException();
	}
	return array_[idx];
}

template <class T>
const T& Array<T>::operator[](const std::size_t idx) const	{
	if (idx >= length_)	{
		throw Array<T>::IndexException();
	}
	return array_[idx];
}

template <class T>
std::size_t	Array<T>::size() const	{	return length_;	}

template <class T>
const char* Array<T>::IndexException::what() const throw()	{
	return "[Error] out of range";
}

#endif
