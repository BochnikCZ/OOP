#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Account.h"

using namespace std;

int Account::objectsCountAccount = 0;

Account::Account(int number, Client* c, double ir)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = ir;
	this->owner = c;
	this->partner = nullptr;

	Account::objectsCountAccount += 1;
}

Account::Account(int number, Client* c, Client* p, double ir)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = ir;
	this->owner = c;
	this->partner = p;

	Account::objectsCountAccount += 1;
}

Account::~Account()
{
	Account::objectsCountAccount -= 1;
}

int Account::GetObjectsCountAccount()
{
	return Account::objectsCountAccount;
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

double Account::SetInterestRate(double rate)
{
	this->interestRate = rate;
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
	this->balance += (this->GetBalance() * this->GetInterestRate());

}