/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:29:37 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 13:06:54 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MULTANTSTACK_TPP__
# define __MULTANTSTACK_TPP__

template <class T>
MutantStack<T>::MutantStack()
: std::stack<T>()	{}

template <class T>
MutantStack<T>::MutantStack(MutantStack const& from)
: std::stack<T>(from)	{}

template <class T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& operand)	{
	if (this != &operand)	{
		std::stack<T>::operator=(operand);
	}
	return (*this);
}

template <class T>
MutantStack<T>::~MutantStack()	{}


template <class T>
typename MutantStack<T>::iterator				MutantStack<T>::begin()			{	return this->c.begin();	}

template <class T>
typename MutantStack<T>::iterator				MutantStack<T>::end()			{	return this->c.end();	}

template <class T>
typename MutantStack<T>::const_iterator			MutantStack<T>::cbegin() const	{	return this->c.cbegin();	}

template <class T>
typename MutantStack<T>::const_iterator			MutantStack<T>::cend() const	{	return this->c.cend();	}

template <class T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rbegin()		{	return this->c.rbegin();	}

template <class T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rend()			{	return this->c.rend();	}

template <class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin() const	{	return this->c.crbegin();	}

template <class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend() const	{	return this->c.crend();	}

#endif
