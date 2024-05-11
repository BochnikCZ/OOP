#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Account.h"
#include "Bank.h"

using namespace std;

int Account::objectsCountAccount = 0;

Account::Account(int number, Client* o)
{
	this->number = number;
	this->owner = o;
	this->balance = 0;
	this->interestRate = Bank::GetDefaultInterestRate();

	Account::objectsCountAccount += 1;

	cout << "Byl vytvoren novy ucet pomoci konstruktoru tridy 'Account'." << endl;
}
Account::Account(int number, Client* o, double ir)
{
	this->number = number;
	this->owner = o;
	this->balance = 0;
	this->interestRate = ir;

	Account::objectsCountAccount += 1;

	cout << "Byl vytvoren novy ucet pomoci konstruktoru tridy 'Account'." << endl;
}

Account::~Account()
{
	Account::objectsCountAccount -= 1;

	cout << "Byl smazan ucet pomoci destruktoru tridy 'Account'." << endl;
}

int Account::GetObjectsCountAccount() {
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

bool Account::CanWithdraw(double a) {
	return (this->balance >= a);
}

void Account::Deposit(double a)
{
	this->balance += a;
}

bool Account::Withdraw(double a) {

	bool success = false;

	if (this->CanWithdraw(a))
	{
		this->balance -= a;
		success = true;
	}

	return success;
}

void Account::AddInterest()
{
	this->balance += (this->GetBalance() * this->GetInterestRate());

}

void Account::Print()
{
	printf("\n");
	cout << "Informace o uctu:" << endl;
	printf("\n");
	cout << "Cislo uctu: " << this->GetNumber() << endl;
	cout << "Vlastnik uctu: " << endl;
	cout << "Jmeno: " << this->GetOwner()->GetName() << endl;
	cout << "ID: " << this->GetOwner()->GetCode() << endl;
	cout << "Partner: (none)" << endl;
	cout << "Zustatek: "  << this->GetBalance() << endl;
	cout << "Urokova sazba: "  << this->GetInterestRate() << endl;
	cout << "Typ uctu: 'normal'" << endl;
	printf("\n");

}