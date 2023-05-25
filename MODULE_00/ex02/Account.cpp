#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += this->_amount;
    this->_displayTimestamp();
    std::cout 
    << " index:" << this->_accountIndex << ";"
    << "amount:" << this->_amount << ";"
    << "created" << std::endl;
}

void Account::_displayTimestamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::cout << "[" << 1900 + ltm->tm_year
    << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
    << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
    << std::setw(2) << std::setfill('0') << 1 + ltm->tm_hour
    << std::setw(2) << std::setfill('0') << 1 + ltm->tm_min
    << std::setw(2) << std::setfill('0') << 1 + ltm->tm_sec << "]";
}

void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout 
    << " accounts:" << getNbAccounts()
    << ";" << "total:" << getTotalAmount()
    << ";" << "deposits:" << getNbDeposits()
    << ";" << "withdrawals:" << getNbWithdrawals()
    << std::endl;
}

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout 
    << " index:" << this->_accountIndex
    << ";" << "amount:" << this->_amount
    << ";" << "deposits:" << this->_nbDeposits
    << ";" << "withdrawals:" << this->_nbWithdrawals
    << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout 
    << " index:" << this->_accountIndex
    << ";" << "p_amount:" << this->_amount
    << ";" << "deposit:" << deposit;

    this->_nbDeposits++;
    this->_amount += deposit;
    
    std::cout
    << ";" << "amount:" << this->_amount
    << ";" << "nb_deposits:" << this->_nbDeposits
    << std::endl;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout
    << " index:" << this->_accountIndex
    << ";" << "p_amount:" << this->_amount;

    if (this->_amount < withdrawal)
    {   std::cout
        << ";" << "withdrawal:refused"
        << std::endl;
        return false;
    }
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;

    std::cout
    << ";" << "withdrawal:" << withdrawal
    << ";" << "amount:" << this->_amount
    << ";" << "nb_withdrawals:" << this->_nbWithdrawals
    << std::endl;
    return true;
}

int Account::checkAmount( void ) const {return this->_amount > 0; }

int Account::getNbAccounts(void){return _nbAccounts;}
int Account::getTotalAmount(void){return _totalAmount;}
int Account::getNbDeposits(void){return _totalNbDeposits;}
int Account::getNbWithdrawals(void){return _totalNbWithdrawals;}


Account::~Account()
{
    Account::_displayTimestamp();
    std::cout 
    << " index:" << this->_accountIndex << ";"
    << "amount:" << this->_amount << ";"
    << "closed" << std::endl;
}