#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Bank.h"

using namespace std;



Bank::Bank(int c, int a) {
	this->clientsCount = 0;
	this->accountsCount = 0;

	this->clients = new Client * [c];
	this->accounts = new Account * [a];
}

Bank::~Bank() {
	for (int i = 0; i < this->clientsCount; i++)
	{
		delete this->clients[i];
	}
	delete[] this->clients;

	for (int i = 0; i < this->accountsCount; i++)
	{
		delete this->accounts[i];
	}
	delete[] this->accounts;

	this->clientsCount = 0;
	this->accountsCount = 0;
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

	this->clients[this->clientsCount] = new Client(code, name);
	this->clientsCount += 1;
	return this->clients[this->clientsCount - 1];
}

Account* Bank::CreateAccount(int n, Client* c) {

	Account* account = new Account(n, c);
	this->accounts[this->accountsCount] = account;
	this->accountsCount += 1;
	return this->accounts[this->accountsCount - 1];
}

Account* Bank::CreateAccount(int n, Client* c, double ir) {

	Account* account = new Account(n, c, ir);
	this->accounts[this->accountsCount] = account;
	this->accountsCount += 1;
	return this->accounts[this->accountsCount - 1];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p) {

	Account* account = new Account(n, c, p);
	this->accounts[this->accountsCount] = account;
	this->accountsCount += 1;
	return this->accounts[this->accountsCount - 1];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir) {

	Account* account = new Account(n, c, p, ir);
	this->accounts[this->accountsCount] = account;
	this->accountsCount += 1;
	return this->accounts[this->accountsCount - 1];
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
	cout << "Vypis uctu registrovanych v bance:" << endl;
	for (int i = 0; i < accountsCount; i++)
	{
		cout << "Cislo uctu: " << this->accounts[i]->GetNumber() << endl;
		cout << "Vlastnik uctu: " << this->accounts[i]->GetOwner()->GetName() << endl;
		if (this->accounts[i]->GetPartner() != nullptr)
		{
			cout << "Partner: " << this->accounts[i]->GetPartner()->GetName() << endl;
		}
		else
		{
			cout << "Partner: (none)" << endl;
		}
		cout << "Zustatek na uctu: " << this->accounts[i]->GetBalance() << endl;
		cout << "Urokova sazba: " << this->accounts[i]->GetInterestRate() << endl;
		cout << endl;
	}
}