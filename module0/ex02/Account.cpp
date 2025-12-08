#include <iostream>
#include "Account.hpp"
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


//constructor
Account::Account(int initial_deposit)
{
    _accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();

    std::cout << " index:" << _accountIndex <<
    ";amount:" << _amount << 
    ";created" << std::endl;
}

//destructor
Account::~Account(void)
{ 
    Account::_displayTimestamp();

    std::cout << " index:" << _accountIndex <<
    ";amount:" << _amount << 
    ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int previous_amount = _amount;

    _amount += deposit;
    _nbDeposits++;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << previous_amount
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{

    if(withdrawal > _amount)
    {
        Account::_displayTimestamp();
        std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";withdrawal:refused:"
              << std::endl;
        return false;
    }
    int previous_amount = _amount;
    _amount -= withdrawal;
    _nbWithdrawals++;

    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;

    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << previous_amount
              << ";withdrawal:" << withdrawal
              << ":amount:" << _amount
              << ";nb_withdrawal:" << _nbWithdrawals
              << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;

}
 
int Account::getNbAccounts()
{
    return Account::_nbAccounts;
}
int Account::getTotalAmount()
{
    return Account::_totalAmount;
}
int Account::getNbDeposits()
{
    return Account::_totalNbDeposits;
}
int Account::getNbWithdrawals()
{
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl; 
}
void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *lt = std::localtime(&now);

    std::cout << "["
              << (lt->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (lt->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << lt->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << lt->tm_hour
              << std::setw(2) << std::setfill('0') << lt->tm_min
              << std::setw(2) << std::setfill('0') << lt->tm_sec
              << "]";
}
