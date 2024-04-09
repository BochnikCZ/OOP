#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Bank.h"

using namespace std;



Bank::Bank(int c, int a) {
	this->clientsCount = c;
	this->accountsCount = a;

	this->clients = new Client * [c];
	this->accounts = new Account * [a];
}

Bank::~Bank() {
	for (int i = 0; i < this->clientsCount; i++)
	{
		delete this->clients;
	}
	delete[] this->clients;

	for (int i = 0; i < this->accountsCount; i++)
	{
		delete this->accounts;

	}
	delete[] this->accounts;
}

Client* Bank::GetClient(int code) {

	for (int i = 0; i < this->clientsCount; i++)
	{
		if (this->clients[i]->GetCode() == code)
		{
			return this->clients[i];
		}
	}

	return nullptr;

}

Client* Bank::CreateClient(int code, string name) {

	this->clients[code] = new Client(code, name);

	return this->clients[code];
}

Account* Bank::CreateAccount(int n, Client* c) {

	Account* account = new Account(n, c);
	this->accounts[n] = account;

	return account;
}

Account* Bank::CreateAccount(int n, Client* c, double ir) {

	Account* account = new Account(n, c, ir);
	this->accounts[n] = account;

	return account;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p) {

	Account* account = new Account(n, c, p);
	this->accounts[n] = account;

	return account;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir) {

	Account* account = new Account(n, c, p, ir);
	this->accounts[n] = account;

	return account;
}

void Bank::AddInterest()
{
	for (int i = 0; i < this->accountsCount; i++)
	{
		this->accounts[i]->AddInterest();
	}
}

Account* Bank::GetAccount(int n) {

	for (int i = 0; i < this->accountsCount; i++)
	{
		if (this->accounts[i]->GetNumber() == n)
		{
			return this->accounts[i];
			break;
		}
	}

	return nullptr;
}

void Bank::Print()
{
	cout << "Výpis úètù registrovaných v bance:" << endl;
	for (int i = 0; i < accountsCount; i++)
	{
		cout << "Cislo uctu: " << this->accounts[i]->GetNumber() << endl;
		cout << "Vlastník úètu: " << this->accounts[i]->GetOwner() << endl;
		cout << "Partner: " << this->accounts[i]->GetPartner() << endl;
		cout << "Zùstatek na úètu: " << this->accounts[i]->GetBalance() << endl;
		cout << "Úroková sazba: " << this->accounts[i]->GetInterestRate() << endl;
		cout << endl;
	}
}