#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.h"

using namespace std;

class Account
{
private:
	static int objectsCountAccount;
	int number;
	double balance;
	double interestRate;

	Client* owner;
	Client* partner;
public:
	static int GetObjectsCountAccount();

	Account(int number, Client* c, double ir);
	Account(int number, Client* c, Client* p, double ir);
	~Account();

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	double SetInterestRate(double rate);
	Client* GetOwner();
	Client* GetPartner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();

};