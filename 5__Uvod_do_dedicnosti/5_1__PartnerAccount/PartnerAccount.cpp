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