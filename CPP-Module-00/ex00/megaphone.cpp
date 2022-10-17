/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:33:22 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/02 23:11:03 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main( int argc, char* argv[] )
{
    std::string str;

    if ( argc > 1 )
	{
		for ( int i = 1; i < argc; i++ )
		{
			std::string	temp = argv[ i ];

			for ( std::size_t j = 0; j < temp.length(); j++ )
			{
				str += std::toupper( temp[ j ] );
			}
			// for ( std::string::iterator it = str.begin(); it != str.end(); it++ )
			// 	*it = std::toupper( *it );
		}
	}
    else
	{
        str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
    std::cout << str << std::endl;
    return 0;
}
