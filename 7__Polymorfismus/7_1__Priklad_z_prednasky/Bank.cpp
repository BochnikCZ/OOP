#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Bank.h"
#include "PartnerAccount.h"

using namespace std;

double Bank::defaultInterestRate = 0.051;

Bank::Bank(int c, int a) {

	this->clients = new Client * [c];
	this->accounts = new Account * [a];
}

Bank::~Bank() {
	int i;
	while (Client::GetObjectsCountClient() != 0)
	{
		i = Client::GetObjectsCountClient();
		i -= 1;
		delete this->clients[i];
	}
	delete[] this->clients;

	while (Account::GetObjectsCountAccount() != 0)
	{
		i = Account::GetObjectsCountAccount();
		i -= 1;
		delete this->accounts[i];
	}
	delete[] this->accounts;

}

void Bank::ModifyInterestRate(double newRate)
{
	for (int i = 0; i < Account::GetObjectsCountAccount(); i++)
	{
		if (this->accounts[i]->GetInterestRate() == Bank::defaultInterestRate)
		{
			this->accounts[i]->SetInterestRate(newRate);
		}
	}

	Bank::defaultInterestRate = newRate;
}

Client* Bank::GetClient(int code) {

	for (int i = 0; i < Client::GetObjectsCountClient(); i++)
	{
		if (this->clients[i]->GetCode() == code)
		{
			return this->clients[i];
		}
	}

	return nullptr;

}

Client* Bank::CreateClient(int code, string name) {
	Client* client = new Client(code, name);
	this->clients[Client::GetObjectsCountClient() - 1] = client;
	return this->clients[Client::GetObjectsCountClient() - 1];
}

Account* Bank::CreateAccount(int n, Client* o) {
	Account* account = new Account(n, o);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return this->accounts[Account::GetObjectsCountAccount() - 1];
}

Account* Bank::CreateAccount(int n, Client* c, double ir) {
	Account* account = new Account(n, c, ir);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return this->accounts[Account::GetObjectsCountAccount() - 1];
}

PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p) {

	PartnerAccount* account = new PartnerAccount(n, c, p);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return account;
}

PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p, double ir) {

	PartnerAccount* account = new PartnerAccount(n, c, p, ir);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return account;
}

CreditAccount* Bank::CreateAccount(int n, double c, Client* o)
{
	CreditAccount* account = new CreditAccount(n, o, c);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return account;
}

CreditAccount* Bank::CreateAccount(int n, Client* o, double ir, double c)
{
	CreditAccount* account = new CreditAccount(n, o, ir, c);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return account;
}

void Bank::AddInterest()
{
	for (int i = 0; i < Account::GetObjectsCountAccount(); i++)
	{
		this->accounts[i]->AddInterest();
	}
}

Account* Bank::GetAccount(int n) {

	for (int i = 0; i < Account::GetObjectsCountAccount(); i++)
	{
		if (this->accounts[i]->GetNumber() == n)
		{
			return this->accounts[i];
			break;
		}
	}

	return nullptr;
}

double Bank::GetDefaultInterestRate()
{
	return Bank::defaultInterestRate;
}

void Bank::Print()
{
	cout << "Vypis uctu registrovanych v bance:" << endl;
	for (int i = 0; i < Account::GetObjectsCountAccount(); i++)
	{
		this->accounts[i]->Print();
	}
	cout << "//////////////////////////////////////////////////////////////////////////" << endl;
}