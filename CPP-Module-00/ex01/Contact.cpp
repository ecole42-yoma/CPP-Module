/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:00:40 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 15:40:24 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

cpp::Contact::Contact( void )
{
	for ( std::size_t i = 0; i < cpp::kSize; i++ )
	{
		table[ i ] = "EmptyField";
	}
}


const std::string& cpp::Contact::Get( ContactFieldName idx ) const
{
	return table[ idx ];
}


void	cpp::Contact::Set( const std::string& str, ContactFieldName idx )
{
	table[ idx ] = str;
}
