#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.h"

using namespace std;

class Account
{
private:
	static int objectsCount;
	static double defaultInterestRate;

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
	~Account();

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	double SetInterestRate(double a);
	Client* GetOwner();
	Client* GetPartner();
	static int GetObjectsCount();
	static double GetDefaultInterestRate();
	static double SetDefalutInterestRate(double dir);
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();

};