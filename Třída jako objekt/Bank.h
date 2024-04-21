#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Account.h"

using namespace std;

class Bank
{
private:
	Client** clients;
	Account** accounts;

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
	void SetDefaultInterestRate( double a );
	void UpdateMissingInterestRate();
	void SetAndUpdateIR(double a);
};