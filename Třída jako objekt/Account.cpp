#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Account.h"

using namespace std;

int Account::objectsCount = 0;
double Account::defaultInterestRate = 0;

Account::Account(int number, Client* c)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = '\0';
	this->owner = c;
	this->partner = nullptr;
	Account::objectsCount += 1;
}
Account::Account(int number, Client* c, double ir)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = ir;
	this->owner = c;
	this->partner = nullptr;
	Account::objectsCount += 1;
}
Account::Account(int number, Client* c, Client* p)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = '\0';
	this->owner = c;
	this->partner = p;
	Account::objectsCount += 1;
}
Account::Account(int number, Client* c, Client* p, double ir)
{
	this->number = number;
	this->balance = 0;
	this->interestRate = ir;
	this->owner = c;
	this->partner = p;
	Account::objectsCount += 1;
}

Account::~Account()
{
	Account::objectsCount -= 1;
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

double Account::SetInterestRate(double a)
{
	this->interestRate = a;
	return this->interestRate;
}

Client* Account::GetOwner() {

	return this->owner;
}

Client* Account::GetPartner() {

	return this->partner;
}

int Account::GetObjectsCount()
{
	return Account::objectsCount;
}

double Account::GetDefaultInterestRate()
{
	return Account::defaultInterestRate;
}

double Account::SetDefalutInterestRate(double dir)
{
	Account::defaultInterestRate = dir;
	return Account::defaultInterestRate;
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
