/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:38:55 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/31 20:00:34 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructeur avec dépôt initial
Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0) {

    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";created" << std::endl;
}

// Destructeur
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= _amount;
}

// Méthode pour effectuer un dépôt
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";deposit:" << deposit << ";amount:" << _amount + deposit
              << ";nb_deposits:" << _nbDeposits + 1 << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (_amount >= withdrawal) {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
                  << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal
                  << ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;       
        return true;
    } else {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
                  << ";withdrawal:" << withdrawal << ";refused" << std::endl;
        return false;
    }
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Méthode privée pour afficher l'horodatage
void Account::_displayTimestamp() {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::cout << "[";
    std::cout << tm.tm_year + 1900 << std::setw(2) << std::setfill('0') << tm.tm_mon + 1 << std::setw(2) << std::setfill('0') << tm.tm_mday;
    std::cout << "_";
    std::cout << tm.tm_hour << std::setw(2) << std::setfill('0') << tm.tm_min << std::setw(2) << std::setfill('0') << tm.tm_sec;
    std::cout << "] ";
}