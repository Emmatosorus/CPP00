// ************************************************************************** //
//                                                                            //
//            Account.cpp for GlobalBanksters United                          //
//            Created on  : Thu Jun 6 10∶43∶07 2024                           //
//            Last update : ...                         					  //
//            Made by : Emma "epolitze" Politzer <epolitze@student.42lyon.fr> //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals= 0;

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

int	Account::getNbAccounts() {
	return (_nbAccounts);
}

int	Account::getTotalAmount() {
	return (_totalAmount);
}

int	Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t time = std::time(0);
	tm		*local = localtime(&time);

	std::cout << "[" << 1900 + local->tm_year;
	if (1 + local->tm_mon < 10)
		std::cout << 0;
	std::cout << 1 + local->tm_mon;
	if (local->tm_mday < 10)
		std::cout << 0;
	std::cout << local->tm_mday;
	std::cout << "_";
	if (local->tm_hour < 10)
		std::cout << 0;
	std::cout << local->tm_hour;
	if (local->tm_min < 10)
		std::cout << 0;
	std::cout << local->tm_min;
	if (local->tm_sec < 10)
		std::cout << 0;
	std::cout << local->tm_sec;
	std::cout << "]";
}

void	Account::makeDeposit(int deposit) {
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

int	Account::checkAmount() const {
	return (_amount);
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal >= _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}
