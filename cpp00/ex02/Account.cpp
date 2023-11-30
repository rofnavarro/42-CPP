/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:01:36 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/30 06:49:25 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "# Bank Info" << std::endl;
	Account::_displayTimestamp();
	std::cout << "| Accounts: " << Account::_nbAccounts << std::endl;
	std::cout << "| Total: " << Account::_totalAmount << std::endl;
	std::cout << "| Deposits: " << Account::_totalNbDeposits << std::endl;
	std::cout << "| Withdraws: " << Account::_totalNbWithdrawals << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
}

Account::Account(int initial_deposit)
{
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "# Creating an Account..." << std::endl;
	this->_accountIndex = Account::getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount = initial_deposit;
	this->_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "| Index: " << this->_accountIndex << std::endl;
	std::cout << "| First Deposit: " << this->_amount << std::endl;
	std::cout << "# Account Created" << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
}

Account::~Account(void)
{
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "# Closing an Account..." << std::endl;
	Account::_displayTimestamp();
	std::cout << "| Index: " << this->_accountIndex << std::endl;
	std::cout << "| Last Withdraw: " << this->_amount << std::endl;
	std::cout << "# Account Closed" << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "# Making a Deposit..." << std::endl;
	Account::_displayTimestamp();
	std::cout << "| Index: " << this->_accountIndex << std::endl;
	std::cout << "| Amount: " << this->_amount << std::endl;
	std::cout << "| Deposit: " << deposit << std::endl;
	this->_amount += deposit;
	std::cout << "| Total after Deposit: " << this->_amount << std::endl;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	std::cout << "| Deposits in this Account: " << this->_nbDeposits << std::endl;
	this->_totalNbDeposits++;
	std::cout << "# Deposit Done" << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "# Making a Withdraw..." << std::endl;
	Account::_displayTimestamp();
	std::cout << "| Index: " << this->_accountIndex << std::endl;
	std::cout << "| Amount: " << this->_amount << std::endl;
	std::cout << "| Withdraw: " << withdrawal << std::endl;
	if (Account::checkAmount() < withdrawal)
	{
		std::cout << "### Withdraw Refused ###" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		std::cout << "| Total after Withdraw: " << this->_amount << std::endl;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "| Withdraws in ths Account: " << this->_nbWithdrawals << std::endl;
		this->_totalNbWithdrawals++;
		std::cout << "# Withdraw Done" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
		return (true);
	}
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "# Status of an Account" << std::endl;
	Account::_displayTimestamp();
	std::cout << "| Index: " << this->_accountIndex << std::endl;
	std::cout << "| Amount: " << this->_amount << std::endl;
	std::cout << "| Deposits: " << this->_nbDeposits << std::endl;
	std::cout << "| Withdrawls: " << this->_nbWithdrawals << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	clock;
	std::tm	*date;

	time(&clock);
	date = localtime(&clock);
	std::cout << "(" << date->tm_year + 1900 << "/" <<
	std::setfill('0') << std::setw(2) << date->tm_mon + 1 << "/" <<
	std::setfill('0') << std::setw(2) << date->tm_mday << " - " <<
	std::setfill('0') << std::setw(2) << date->tm_hour << ":" <<
	std::setfill('0') << std::setw(2) << date->tm_min << ":" <<
	std::setfill('0') << std::setw(2) << date->tm_sec << ")" << std::endl;
}
