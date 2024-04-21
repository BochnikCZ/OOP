#pragma once
#include <iostream>
#include <string>

#include "Account.h"
#include "PartnerAccount.h"

using namespace std;

class Bank
{
private:
	Client** clients;
	int clientsCount;

	Account** accounts;
	int accountsCount;

public:
	Bank(int c, int a);
	~Bank();

	Client* GetClient(int code);
	Account* GetAccount(int n);

	Client* CreateClient(int code, string name);

	Account* CreateAccount(int n, Client* c);
	Account* CreateAccount(int n, Client* c, double ir);
	Account* CreateAccount(int n, Client* c, Client* p);
	Account* CreateAccount(int n, Client* c, Client* p, double ir);

	void AddInterest();
	void Print();
};