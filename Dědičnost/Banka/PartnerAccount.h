#pragma once
#include <iostream>
#include <string>

#include "Account.h"
using namespace std;

class PartnerAccount : public Account
{
private:
	Client* partner;

public:
	PartnerAccount(int n, Client* o, Client* p);
	PartnerAccount(int n, Client* o, Client* p, double ir);

	Client* GetPartner();
};