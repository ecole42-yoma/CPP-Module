/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:29:37 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 15:47:59 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __PHONE_BOOK_H__
# define __PHONE_BOOK_H__

# include "Contact.hpp"

# define MAX_CONTACT 8
# define SEARCH_FIELD_SIZE 4
# define MAX_FIELD_SIZE 10

namespace cpp
{

	enum CommandType
	{
		kJust,
		kUpper,
		kNumber
	};

	class PhoneBook
	{

		private:
			void		Add( void );
			void		Search( void );
			void		Exit( void );
			void		Help( void );

			Contact		_contacts[ MAX_CONTACT ];
			std::size_t	_contact_count;
			std::size_t	_contact_size;
			int		 	_running_status;
			int		 	_running_status_search;
			std::string	_field_name[ kSize ];
			std::string	_command[ kDarkestSecret ];
			void		( cpp::PhoneBook::*_fp[ kDarkestSecret ] )( void );


		public:
			PhoneBook( void );
			~PhoneBook( void );
			void			OpenTheBook( void );

	};
}

#endif /* __PHONE_BOOK_H__ */
