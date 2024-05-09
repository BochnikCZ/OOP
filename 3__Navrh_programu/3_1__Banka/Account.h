#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.h"

using namespace std;

class Account
{
private:
	int number;
	double balance;
	double interestRate;

	Client* owner;
	Client* partner;
public:
	Account(int number, Client* c);
	Account(int number, Client* c, double ir);
	Account(int number, Client* c, Client* p);
	Account(int number, Client* c, Client* p, double ir);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	Client* GetPartner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();

};