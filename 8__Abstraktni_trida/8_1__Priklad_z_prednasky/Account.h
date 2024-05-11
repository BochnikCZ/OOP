#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "AbstractAccount.h"

using namespace std;

class Account : public AbstractAccount
{
private:
	int number;
	double balance;
	double interestRate;

	Client* owner;


	static int objectsCountAccount;

public:
	Account(int number, Client* c);
	Account(int number, Client* c, double ir);
	virtual ~Account();

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	virtual bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();

	virtual void Print();


	double SetInterestRate(double rate);
	static int GetObjectsCountAccount();
};