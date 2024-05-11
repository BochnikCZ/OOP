#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "PartnerAccount.h"

using namespace std;

PartnerAccount::PartnerAccount(int n, Client* o, Client* p) : Account(n, o)
{
	this->partner = p;
	cout << "Byl vytvoren novy ucet pomoci konstruktoru tridy 'PartnerAccount'." << endl;
}

PartnerAccount::PartnerAccount(int n, Client* o, Client* p, double ir) : Account(n, o, ir)
{
	this->partner = p;
	cout << "Byl vytvoren novy ucet pomoci konstruktoru tridy 'PartnerAccount'." << endl;
}

PartnerAccount::~PartnerAccount()
{
	cout << "Byl smazan ucet pomoci destruktoru tridy 'PartnerAccount'." << endl;
}

Client* PartnerAccount::GetPartner()
{
	return this->partner;
}

void PartnerAccount::Print()
{
	printf("\n");
	cout << "Informace o uctu:" << endl;
	printf("\n");
	cout << "Cislo uctu: " << this->GetNumber() << endl;
	cout << "Vlastnik uctu: " << endl;
	cout << "Jmeno: " << this->GetOwner()->GetName() << endl;
	cout << "ID: " << this->GetOwner()->GetCode() << endl;
	cout << "Partner: " << endl;
	cout << "Jmeno: " << this->GetPartner()->GetName() << endl;
	cout << "ID: " << this->GetPartner()->GetCode() << endl;
	cout << "Zustatek: " << this->GetBalance() << endl;
	cout << "Urokova sazba: " << this->GetInterestRate() << endl;
	cout << "Typ uctu: 'normal'" << endl;
	printf("\n");

}