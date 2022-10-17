/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:59:20 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/26 10:59:35 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MULTANTSTACK_HPP__
# define __MULTANTSTACK_HPP__

# include <stack>

template <class T>
class MutantStack : public std::stack<T>	{

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack();
		MutantStack(MutantStack const& from);
		MutantStack& operator=(MutantStack const& operand);
		virtual ~MutantStack();

		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;

};

# include "MutantStack.tpp"

#endif
