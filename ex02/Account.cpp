/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:39:40 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/08 00:19:20 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    this->_amount = initial_deposit;
    this->_totalAmount += this->_amount;
    this->_accountIndex = this->_nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

int Account::getNbAccounts(void) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout
        << "accounts:" << Account::getNbAccounts()
        << ";total:" << Account::getTotalAmount()
        << ";deposits:" << Account::getNbDeposits()
        << ";withdrawals:" << Account::getNbWithdrawals()
        << std::endl;
}

Account::~Account(void) {
    this->_totalAmount -= this->_amount;
    this->_nbAccounts--;
    this->_totalNbDeposits -= this->_nbDeposits;
    this->_totalNbWithdrawals -= this->_nbWithdrawals;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    ++this->_totalNbDeposits;
    ++this->_nbDeposits;
    this->_totalAmount += deposit;
    this->_amount += deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (this->_amount < withdrawal)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
        return (false);
    }
    ++this->_totalNbWithdrawals;
    ++this->_nbWithdrawals;
    this->_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const {
    return (this->_amount);
}

void    Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void) {
    struct tm datetime;
    char    buff[256];

    time_t  now = time(0);
    localtime_r(&now, &datetime);
    strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", &datetime);
    std::cout << "[" << buff << "] ";
}
