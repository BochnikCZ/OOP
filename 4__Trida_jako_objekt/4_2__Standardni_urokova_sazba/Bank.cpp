#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Bank.h"

using namespace std;

double Bank::defaultInterestRate = 5.1;

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

Account* Bank::CreateAccount(int n, Client* c) {

	Account* account = new Account(n, c, Bank::defaultInterestRate);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return this->accounts[Account::GetObjectsCountAccount() - 1];
}

Account* Bank::CreateAccount(int n, Client* c, double ir) {

	Account* account = new Account(n, c, ir);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return this->accounts[Account::GetObjectsCountAccount() - 1];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p) {

	Account* account = new Account(n, c, p, Bank::defaultInterestRate);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return this->accounts[Account::GetObjectsCountAccount() - 1];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir) {

	Account* account = new Account(n, c, p, ir);
	this->accounts[Account::GetObjectsCountAccount() - 1] = account;
	return this->accounts[Account::GetObjectsCountAccount() - 1];
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

void Bank::Print()
{
	cout << "Vypis uctu registrovanych v bance:" << endl;
	for (int i = 0; i < Account::GetObjectsCountAccount(); i++)
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