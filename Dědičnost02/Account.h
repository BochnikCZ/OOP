#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.h"
#include "Account.cpp"
#include "Bank.h"

using namespace std;

class Account
{
private:
	int number;
	double balance;
	double interestRate;

	Client* owner;
public:
	Account(int number, Client* c);
	Account(int number, Client* c, double ir);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();
	
};