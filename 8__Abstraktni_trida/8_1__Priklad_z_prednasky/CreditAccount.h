#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Account.h"

using namespace std;

class CreditAccount : public Account
{
private:
	double credit;

public:
	CreditAccount(int n, Client* o, double c);
	CreditAccount(int n, Client* o, double ir, double c);
	virtual ~CreditAccount();

	virtual bool CanWithdraw(double a);

	double GetCredit();
	void Print();
};