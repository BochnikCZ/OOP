#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Account.h"

using namespace std;


Account::Account(int number, Client* o)
{
	this->number = number;
	this->owner = o;
	this->balance = 0;
	this->interestRate = 0;

	cout << "Byl vytvoren novy ucet pomoci konstruktoru tridy 'Account'." << endl;
}
Account::Account(int number, Client* o, double ir)
{
	this->number = number;
	this->owner = o;
	this->balance = 0;
	this->interestRate = ir;

	cout << "Byl vytvoren novy ucet pomoci konstruktoru tridy 'Account'." << endl;
}

Account::~Account()
{
	cout << "Byl smazan ucet pomoci destruktoru tridy 'Account'." << endl;
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

	if (this->CanWithdraw(a) == true)
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
