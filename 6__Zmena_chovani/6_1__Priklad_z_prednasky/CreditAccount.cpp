#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "CreditAccount.h"

using namespace std;

CreditAccount::CreditAccount(int n, Client* o, double c) : Account(n, o)
{
	this->credit = c;
}

CreditAccount::CreditAccount(int n, Client* o, double ir, double c) : Account(n, o, ir)
{
	this->credit = c;
}

bool CreditAccount::CanWithdraw(double a)
{
	return (this->GetBalance() + this->credit >= a);
}

bool CreditAccount::Withdraw(double a)
{
	bool success = false;
	if (this->CreditAccount::CanWithdraw(a) == true)
	{
		this->balance -= a;
		success = true;
	}
	return success;
}