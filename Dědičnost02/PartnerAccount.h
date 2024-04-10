#include <iostream>
#include "Account.h"
#include "Bank.h"
#include "Client.h"

class PartnerAccount : public Account
{
private:
	Client* partner;
public:
	PartnerAccount(int n, Client* c, Client* p);
	PartnerAccount(int n, Client* C, Client* p, double ir);

	Client* GetPartner();
};