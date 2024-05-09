#include <iostream>
#include <string>

#include "Bank.h"
using namespace std;

int main()
{
    //Account* a;
    PartnerAccount* pa;

// Poradi volani konstruktoru: 1. potomek, 2. predek
// Poradi vyhodnocovani konstruktoru: 1. predek, 2. potomek
    pa = new PartnerAccount(0, new Client(0, "Smith"), new Client(1, "Jones"));
    //a = pa;

    //cout << a->GetOwner()->GetName() << endl;
    cout << pa->GetPartner()->GetName() << endl;            


// Poradi volani destruktoru: 1. potomek, 2. predek
// Poradi vyhodnocovani destruktoru: 1. potomek, 2. predek
    delete pa;
    getchar();
    return 0;
}