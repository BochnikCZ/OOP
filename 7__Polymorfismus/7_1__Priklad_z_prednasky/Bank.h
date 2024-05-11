#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "CreditAccount.h"
#include "PartnerAccount.h"

using namespace std;

class Bank
{
private:
	static double defaultInterestRate;

	Client** clients;
	Account** accounts;

public:
	Bank(int c, int a);
	~Bank();

	Client* GetClient(int code);
	Account* GetAccount(int n);

	static double GetDefaultInterestRate();

	Client* CreateClient(int code, string name);

	Account* CreateAccount(int n, Client* o);
	Account* CreateAccount(int n, Client* o, double ir);
	PartnerAccount* CreateAccount(int n, Client* o, Client* p);
	PartnerAccount* CreateAccount(int n, Client* o, Client* p, double ir);
	CreditAccount* CreateAccount(int n, double c, Client* o);
	CreditAccount* CreateAccount(int n, Client* o, double ir, double c);

	void AddInterest();
	void Print();
	void ModifyInterestRate(double newRate);
};