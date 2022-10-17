/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 03:52:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/22 03:54:44 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t	serialize(Data* ptr)	{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)	{
    return reinterpret_cast<Data*>(raw);
}
