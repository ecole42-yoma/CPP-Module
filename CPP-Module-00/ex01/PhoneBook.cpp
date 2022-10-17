/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:33:14 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 16:14:53 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

namespace
{

	std::string	_CutString( std::string const& org )
	{
		std::string	temp = org;

		if ( temp.length() > MAX_FIELD_SIZE )
		{
			temp.erase( MAX_FIELD_SIZE - 1 );
			temp.insert( MAX_FIELD_SIZE - 1, "." );
		}
		return temp;
	}


	void	_MakeUpper( std::string& str )
	{
		for ( std::string::iterator it = str.begin(); it != str.end(); it++ )
		{
			*it = std::toupper( *it );
		}
	}


	std::string _GetCommand( cpp::CommandType key )
	{
		std::string str;

		std::getline( std::cin, str );
		if ( str.empty() )
		{
			return "";
		}
		if ( key == cpp::kUpper )
		{
			_MakeUpper( str );
		}
		else if ( key == cpp::kNumber )
		{
			int	is_there_num = 0;

			if ( !isdigit( str[0] ) )
			{
				_MakeUpper( str );
				if ( str == "EXIT" || str == "SEARCH" )
				{
					return str;
				}
				else
				{
					return "ERROR";
				}
			}
			for ( std::string::iterator it = str.begin(); it != str.end(); it++ )
			{
				if ( !isdigit( *it ) )
				{
					is_there_num |= 1;
				}
				if ( is_there_num )
				{
					std::cout << "Error: There aren't only digit number" << std::endl;
					return "ERROR";
				}
			}
		}
		return str;
	}


	void	_PrintWidth( std::string const& str, std::size_t idx = 0, std::size_t max = SEARCH_FIELD_SIZE, \
							std::size_t w_size = MAX_FIELD_SIZE, cpp::CommandType key = cpp::kJust )
	{
		std::cout << std::setw( static_cast<int>(w_size) ) << str;
		if ( idx < max - 1 )
		{
			if ( key == cpp::kJust)
			{
				std::cout << "|";
			}
			else
			{
				std::cout << ": ";
			}
		}
		else
		{
			std::cout << std::endl;
		}
	}


	void _PrintBarline( void )
	{
		for ( std::size_t i = 0; i < SEARCH_FIELD_SIZE; i++ )
		{
			_PrintWidth( "----------", i );
		}
	}


	void _PrintMenu( cpp::CommandType key = cpp::kJust, std::size_t contact_size = 0 )
	{
		switch ( static_cast< int > ( key ) )
		{
			case cpp::kJust:
				std::cout << "Main - [ ADD ] [ SEARCH ] [ EXIT ] [ HELP ]" << std::endl;
				std::cout << ">";
				break;

			case cpp::kNumber:
				if ( contact_size > 0 )	{
					std::cout << "\nSearch - [ 0 ~ " << std::to_string( contact_size - 1 ) << " ]";
					std::cout << " [ SEARCH ] [ EXIT ]" << std::endl;	}
				else	{
					std::cout << "\nSearch - [ Empty ] [ SEARCH ] [ EXIT ]" << std::endl;
					std::cout << "Warning: PhoneBook is Empty. Need to add contact at least once" << std::endl;	}
				std::cout << ">> ";
				break ;

			case cpp::kUpper:
				std::cout << "\nExit - [ Y ] [ N ]" << std::endl;
				std::cout << ">> ";
				break ;

			default:
				break ;
		}
	}


	void	_PrintContacts( cpp::Contact const* page, std::size_t const& size )
	{
		std::cout << std::endl;
		std::cout << "[Contacts List]" << std::endl;
		_PrintBarline();
		_PrintWidth( "index", 0 );
		_PrintWidth( "first name", 1 );
		_PrintWidth( "last name", 2 );
		_PrintWidth( "nickname", 3 );
		_PrintBarline();
		for ( std::size_t i = 0; i < size; i++ )
		{
			_PrintWidth( std::to_string( i ) , 0 );
			for ( std::size_t j = 0; j < SEARCH_FIELD_SIZE - 1; j++ )
			{
				_PrintWidth( _CutString( page[ i ].Get( static_cast< cpp::ContactFieldName >( j ))), j, SEARCH_FIELD_SIZE - 1 );
			}
			_PrintBarline();
		}
	}


	bool	_SearchStep( std::string& cmd, cpp::Contact* page, std::size_t& size, int& status )
	{
		_PrintMenu( cpp::kNumber, size );
		cmd = _GetCommand( cpp::kNumber );
		if ( cmd.empty() )
		{
			return false;
		}
		else if ( cmd == "ERROR" )
		{
			std::cout << "Put valid index number" << std::endl;
		}
		else if ( cmd == "EXIT" )
		{
			std::cout << "Exit [search mode]" << std::endl;
			status = 0 ;
			}
		else if ( cmd == "SEARCH" )
		{
			_PrintContacts( page, size );
		}
		else
		{
			return true;
		}
		return false;
	}


	bool	_CheckIdx( std::string const& cmd, std::size_t const& size, std::size_t& org_idx )
	{
		std::size_t	idx;

		std::stringstream( cmd ) >> idx;
		org_idx = idx;
		if ( idx >= size )
		{
			if ( !size )
			{
				std::cout << "Warning: PhoneBook is empty" << std::endl;
			}
			else
			{
				std::cout << "Warning: Out of Range: " << std::to_string( idx ) << std::endl;
			}
			return false;
		}
		return true;
	}


	void	_PrintContactDetail( std::size_t const& idx, std::string const* field_name, cpp::Contact const* page)
	{
		std::cout << "\n[Contact Info]" << std::endl;
		std::cout << "---------------" << std::endl;
		_PrintWidth( "INDEX", 0, 2, 14 );
		std::cout << " " << std::to_string( idx ) << std::endl;
		for ( std::size_t field = 0; field < cpp::kSize; field++ )
		{
			cpp::ContactFieldName key = static_cast< cpp::ContactFieldName >( field );
			std::cout << "---------------" << std::endl;
			_PrintWidth( field_name[ key ], 0, 2, 14 );
			std::cout << " " << page[ idx ].Get( key ) << std::endl;
		}
		std::cout << "---------------" << std::endl;
	}


} /* namespace end */




cpp::PhoneBook::PhoneBook( void ) : _contact_count(0), _contact_size(0), _running_status(1)
{
	std::cout << "\n * Welcome [ PhoneBook ] *\n" << std::endl;
	{
		std::string field_name[ kSize ] =
		{
			"First Name",
			"Last Name",
			"Nick Name",
			"Phone Number",
			"Darkest Secret"
		};

		for ( std::size_t i = 0; i < kSize; i++ )
		{
			_field_name[ i ] = field_name[ i ];
		}
	}
	{
		std::string cmd[ kDarkestSecret ] =
		{
			"ADD",
			"SEARCH",
			"EXIT",
			"HELP"
		};

		for ( std::size_t i = 0; i < kDarkestSecret; i++ )
		{
			_command[ i ] = cmd[ i ];
		}
	}
	{
		void	( cpp::PhoneBook::*fp[ kDarkestSecret ] )( void ) =
		{
			&cpp::PhoneBook::Add,
			&cpp::PhoneBook::Search,
			&cpp::PhoneBook::Exit,
			&cpp::PhoneBook::Help
		};

		for ( std::size_t i = 0; i < kDarkestSecret; i++ )
		{
			_fp[ i ] = fp[ i ];
		}
	}
}


cpp::PhoneBook::~PhoneBook( void )	{	std::cout << " * Exit [ PhoneBook ] *" << std::endl;	}


void	cpp::PhoneBook::OpenTheBook( void )
{
	std::string cmd;
	std::string	temp;

	while ( _running_status )
	{
		_PrintMenu();
		temp = _GetCommand( kJust );
		cmd = temp;
		_MakeUpper( cmd );
		if ( !cmd.empty() )
		{
			int idx = 0;

			while ( idx < kDarkestSecret && cmd != _command[ idx ] )
			{
				idx++;
			}
			if ( idx < kDarkestSecret )
			{
				( this->*_fp[ idx ] )();
			}
			else
			{
				std::cout << "Error: Invalid Command : " << temp << std::endl;
			}
		}
		std::cout << std::endl;
	}
}


void	cpp::PhoneBook::Help( void )
{
	std::cout << "ADD   : Add contact\n" << std::endl;
	std::cout << "SEARCH: Search contact" << std::endl;
	std::cout << "   0~7: Search index" << std::endl;
	std::cout << "  EXIT: Exit Search mode\n" << std::endl;
	std::cout << "EXIT  : Exit PhoneBook\n" << std::endl;
	std::cout << "HELP  : Show this message\n" << std::endl;
}


void	cpp::PhoneBook::Exit( void )
{
	std::string cmd;
	std::string	temp;

	while ( _running_status )
	{
		_PrintMenu( kUpper);
		temp = _GetCommand( kJust );
		cmd = temp;
		_MakeUpper( cmd );
		if ( cmd == "Y" )
		{
			_running_status = 0;
		}
		else if ( cmd == "N" )
		{
			break ;
		}
		else
		{
			std::cout << "Error: Invalid Command : " << temp << std::endl;
		}
		std::cout << std::endl;
	}
}


void	cpp::PhoneBook::Add( void )
{
	cpp::Contact	page;

	std::cout << "\n[Add Contacts]" << std::endl;
	for ( std::size_t field = 0; field < kSize; field++ )
	{
		ContactFieldName key = static_cast< ContactFieldName >( field );

		while ( true )
		{
			std::string context;
			_PrintWidth( _field_name[ key ], 0, 2, 14, kUpper );
			context = _GetCommand( kJust );
			if ( context.empty() )
			{
				std::cout << "Error: Empty Value Doesn't allow in \'ADD\' step" << std::endl;
				continue ;
			}
			page.Set( context, key );
			break ;
		}
	}
	_contacts[ _contact_count++ ] = page;
	if ( _contact_count >= MAX_CONTACT )
	{
		_contact_count = 0;
	}
	if ( _contact_size < MAX_CONTACT )
	{
		_contact_size++;
	}
}


void	cpp::PhoneBook::Search( void )
{
	std::string cmd;

	_PrintContacts( _contacts, _contact_size );
	_running_status_search = 1;
	while ( _running_status_search )
	{
		if ( _SearchStep( cmd, _contacts, _contact_size, _running_status_search ) )
		{
			std::size_t	idx;
			if ( _CheckIdx( cmd, _contact_size, idx ) )
			{
				_PrintContactDetail( idx, _field_name, _contacts );
			}
		}
	}
}
