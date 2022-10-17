/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:44:27 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 15:39:17 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __CONTACT_H__
# define __CONTACT_H__

# include <string>

namespace cpp
{

	enum ContactFieldName
	{
		kFirstName,
		kLastName,
		kNickName,
		kPhoneNumber,
		kDarkestSecret,
		kSize
	};

	class	Contact
	{

		public:
			Contact( void );
			void				Set( const std::string& str, ContactFieldName idx );

			const std::string&	Get( ContactFieldName idx ) const;


		private:
			std::string table[ kSize ];

	};

}
#endif /* __CONTACT_H__ */
