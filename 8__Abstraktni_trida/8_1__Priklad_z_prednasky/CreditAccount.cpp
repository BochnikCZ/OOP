#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "CreditAccount.h"

using namespace std;

CreditAccount::CreditAccount(int n, Client* o, double c) : Account(n, o)
{
	this->credit = c;

	cout << "CreditAccount constructor" << endl;
}

CreditAccount::CreditAccount(int n, Client* o, double ir, double c) : Account(n, o, ir)
{
	this->credit = c;

	cout << "CreditAccount constructor" << endl;
}

CreditAccount::~CreditAccount()
{
	cout << "CreditAccount destructor" << endl;
}

double CreditAccount::GetCredit()
{
	return this->credit;
}

bool CreditAccount::CanWithdraw(double a)
{
	return (this->GetBalance() + this->credit >= a);
}

void CreditAccount::Print()
{
	printf("\n");
	cout << "Informace o uctu:" << endl;
	printf("\n");
	cout << "Cislo uctu: " << this->GetNumber() << endl;
	cout << "Vlastnik uctu: " << endl;
	cout << "Jmeno: " << this->GetOwner()->GetName() << endl;
	cout << "ID: " << this->GetOwner()->GetCode() << endl;
	cout << "Partner: (none)" << endl;
	cout << "Zustatek: " << this->GetBalance() << endl;
	cout << "Urokova sazba: " << this->GetInterestRate() << endl;
	cout << "Typ uctu: credit account" << endl;
	cout << "Credit: " << this->GetCredit() << endl;
	printf("\n");
}