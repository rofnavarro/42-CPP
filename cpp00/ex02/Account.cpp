/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:01:36 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/29 20:33:27 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

static int	Account::getNbAccounts(void)
{
	return (this->_nbAccounts);
}

static int	Account::getTotalAmount(void)
{
	return (this->_totalAmount);
}

static int	Account::getNbDeposits(void)
{
	return (this->_totalNbDeposits);
}

static int	Account::getNbWithdrawals(void)
{
	return (this->_totalNbWithdrawals)
}

static void	Account::displayAccountsInfos(void)
{
	std::cout << "# Account Info" << std::endl;
	Account::_displayTimestamp();
	std::cout << "| Accounts: " << this->_nbAccounts << std::endl;
	std::cout << "| Total: " << this->_totalNbDeposits << std::endl;
	std::cout << "| Deposits: " << this->_totalNbDeposits << std::endl;
	std::cout << "| Withdraws: " << this->_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
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
}

Account::~Account(void)
{
	std::cout << "# Closing an Account..." << std::endl;
	Account::_displayTimestamp();
	std::cout << "| Index: " << this->_accountIndex << std::endl;
	std::cout << "| Last Withdraw: " << this->_amount << std::endl;
	std::cout << "# Account Closed" << std::endl;
}
