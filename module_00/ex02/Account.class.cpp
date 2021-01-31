#include <ctime>
#include <iostream>

#include "Account.class.hpp"

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

int Account::getNbCheckAmountCalls() {
    return _totalCheckAmountCalls;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts)
    , _amount(initial_deposit)
    , _nbDeposits(0)
    , _nbWithdrawals(0) {
    ++_nbAccounts;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";created"
              << std::endl;
}

Account::~Account() {
    --_nbAccounts;
    _totalAmount -= _amount;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed"
              << std::endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _totalAmount += deposit;
    ++_nbDeposits;
    ++_totalNbDeposits;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount - deposit
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (checkAmount() >= withdrawal) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        ++_nbWithdrawals;
        ++_totalNbWithdrawals;

        _displayTimestamp();
        std::cout << " index:" << _accountIndex
                  << ";p_amount:" << _amount + withdrawal
                  << ";withdrawal:" << withdrawal
                  << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals
                  << std::endl;

        return true;
    } else {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:" << "refused"
                  << std::endl;

        return false;
    }
}

int Account::checkAmount() const {
    ++_totalCheckAmountCalls;
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t now = time(0);
    std::tm local = *localtime(&now);
    char buf[42];
    std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &local);
    std::cout << '[' << buf << ']';
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalCheckAmountCalls = 0;
