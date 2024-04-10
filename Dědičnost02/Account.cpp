#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Account.h"

using namespace std;


Account::Account(int number, Client* c)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = 0;
	this->owner = c;
	this->partner = nullptr;
}
Account::Account(int number, Client* c, double ir)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = ir;
	this->owner = c;
	this->partner = nullptr;
}

int Account::GetNumber() {

	return this->number;
}

double Account::GetBalance() {

	return this->balance;
}

double Account::GetInterestRate() {

	return this->interestRate;
}

Client* Account::GetOwner() {

	return this->owner;
}

Client* Account::GetPartner() {

	return this->partner;
}

bool Account::CanWithdraw(double a) {
	if (this->balance >= a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Account::Deposit(double a)
{
	this->balance += a;
}

bool Account::Withdraw(double a) {

	if (CanWithdraw(a) == true)
	{
		this->balance = this->balance - a;
		return true;
	}
	return false;
}

void Account::AddInterest()
{
	this->balance += (this->balance * this->interestRate);

}

Account::~Account() {

	delete this->owner;
	delete this->partner;
}