#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Bank.h"

using namespace std;



Bank::Bank(int c, int a) {

	this->clients = new Client * [c];
	this->accounts = new Account * [a];

	cout << "Uspesne jste zalozili novou bankovni spolecnost. Gratulujeme!" << endl;
}

Bank::~Bank() {

	int temp_clientscount = Client::GetObjectsCount();
	int temp_accountscount = Account::GetObjectsCount();

	for (int i = 0; i < temp_clientscount; i++)
	{
		delete this->clients[i];
	}
	delete[] this->clients;

	for (int i = 0; i < temp_accountscount; i++)
	{
		delete this->accounts[i];
	}
	delete[] this->accounts;


	cout << "Ukoncili jste cinnost Vasi bankovni spolecnosti. Jaka to skoda!" << endl;
}

Client* Bank::GetClient(int code) {

	for (int i = 0; i < Client::GetObjectsCount(); i++)
	{
		if (this->clients[i]->GetCode() == code)
		{
			return this->clients[i];
		}
	}

	return nullptr;

}

Client* Bank::CreateClient(int code, string name) {

	this->clients[Client::GetObjectsCount() - 1] = new Client(code, name);

	cout << "Novy klient evidovan. Vitejte!" << endl;
	cout << "Jmeno klienta: " << name << ", ID: " << code << endl;
	cout << "Aktualni pocet registrovanych klientu: " << Client::GetObjectsCount() << endl;
	return this->clients[ Client::GetObjectsCount() - 1 ];
}

Account* Bank::CreateAccount(int n, Client* c) {

	Account* account = new Account(n, c);
	this->accounts[Account::GetObjectsCount() - 1] = account;
	
	cout << "Doslo k uspesnemu vytvoreni noveho uctu!" << endl;
	cout << "Jmeno vlastnika uctu: " << c->GetName() << "\nCislo uctu: " << n << endl;
	cout << "Aktualni pocet bankovnich uctu: " << Account::GetObjectsCount() << endl;
	
	return this->accounts[Account::GetObjectsCount() - 1];
}

Account* Bank::CreateAccount(int n, Client* c, double ir) {

	Account* account = new Account(n, c, ir);
	this->accounts[Account::GetObjectsCount() - 1] = account;

	cout << "Doslo k uspesnemu vytvoreni noveho uctu!" << endl;
	cout << "Jmeno vlastnika uctu: " << c->GetName() << "\nCislo uctu: " << n << "\nVyse urokove sazby: " << ir << endl;
	cout << "Aktualni pocet bankovnich uctu: " << Account::GetObjectsCount() << endl;

	return this->accounts[Account::GetObjectsCount() - 1];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p) {

	Account* account = new Account(n, c, p);
	this->accounts[Account::GetObjectsCount() - 1] = account;

	cout << "Doslo k uspesnemu vytvoreni noveho uctu!" << endl;
	cout << "Jmeno vlastnika uctu: " << c->GetName() << "\nCislo uctu: " << n << "\nPartner: " << p->GetName() << endl;
	cout << "Aktualni pocet bankovnich uctu: " << Account::GetObjectsCount() << endl;
	
	return this->accounts[Account::GetObjectsCount() - 1];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir) {

	Account* account = new Account(n, c, p, ir);
	this->accounts[Account::GetObjectsCount() - 1] = account;

	cout << "Doslo k uspesnemu vytvoreni noveho uctu!" << endl;
	cout << "Jmeno vlastnika uctu: " << c->GetName() << "\nCislo uctu: " << n << "\nPartner: " << p->GetName() << "\nVyse urokove sazby: " << ir << endl;
	cout << "Aktualni pocet bankovnich uctu: " << Account::GetObjectsCount() << endl;

	return this->accounts[Account::GetObjectsCount() - 1];
}

void Bank::AddInterest()
{
	for (int i = 0; i < Account::GetObjectsCount(); i++)
	{
		this->accounts[i]->AddInterest();
	}

	cout << "Vsem uctum byl pridan urok." << endl;
}

Account* Bank::GetAccount(int n) {

	for (int i = 0; i < Account::GetObjectsCount(); i++)
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
	for (int i = 0; i < Account::GetObjectsCount(); i++)
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


void Bank::SetDefaultInterestRate(double a)
{
	Account::SetDefalutInterestRate(a);
	cout << "Byla nastavena nova defaultni hodnota urokove sazby." << endl;
}

void Bank::UpdateMissingInterestRate()
{
	for (int i = 0; i < Account::GetObjectsCount(); i++)
	{
		if (this->accounts[i]->GetInterestRate() == '\0')
		{
			this->accounts[i]->SetInterestRate(Account::GetDefaultInterestRate());
		}
	}

	cout << "Vsem uctum bez nastavene urokove sazby se nastavila defaultni hodnota." << endl;
}

void Bank::SetAndUpdateIR(double a)
{
	SetDefaultInterestRate(a);
	UpdateMissingInterestRate();
}