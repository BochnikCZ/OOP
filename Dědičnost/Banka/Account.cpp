#include <iostream>
#include <string>

#include "Account.h"

using namespace std;


Account::Account(int number, Client* c)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = 0;
	this->owner = c;
}
Account::Account(int number, Client* c, double ir)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = ir;
	this->owner = c;
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