/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:08:59 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/09 16:27:02 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <chrono>


int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;


int	Account::getNbAccounts( void )		{	return _nbAccounts;			}
int	Account::getTotalAmount( void )		{	return _totalAmount;		}
int	Account::getNbDeposits( void )		{	return _totalNbDeposits;	}
int	Account::getNbWithdrawals( void )	{	return _totalNbWithdrawals;	}


void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}


Account::Account( int initial_deposit ) : _accountIndex( _nbAccounts++ ), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}


Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}


void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if ( deposit > 0 )
	{
		int	new_amount = _amount + deposit;

		std::cout << "deposit:" << deposit << ";";
		std::cout << "amount:" << new_amount << ";";
		_nbDeposits++;
		std::cout << "nb_deposits:" << _nbDeposits << std::endl;
		_amount = new_amount;
		_totalNbDeposits += _nbDeposits;
		_totalAmount += deposit;
	}
	else
	{
		std::cout << "deposit:refused"<< std::endl;
	}
}


bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if ( withdrawal > 0 && ( _amount - withdrawal >= 0 ) )
	{
		int	new_amount = _amount - withdrawal;

		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << new_amount << ";";
		_nbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount = new_amount;
		_totalNbWithdrawals += _nbWithdrawals;
		_totalAmount -= withdrawal;
		return true;
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
	}
	return false;
}


int	Account::checkAmount( void ) const	{	return _amount;	}


void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}


void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532] ";

	// std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );

	// std::cout << "[";
	// std::cout << std::put_time( std::localtime( &time ), "%Y%m%d_%H%M%S" );
	// std::cout << "] ";
}


Account::Account( void )	{	}
