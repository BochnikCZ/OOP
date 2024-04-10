#include <iostream>
#include <string>

#include "Account.h"
#include "Client.h"
#include "Bank.h"
#include "PartnerAccount.h"
using namespace std;

int main()
{
    Account* a;
    PartnerAccount* pa;
    
    Bank* bank = new Bank(100, 1000);
    Client* c = bank->CreateClient(0, "Smith");
    Client* p = bank->CreateClient(1, "Jones");
    a = bank->CreateAccount(0, c);

}
