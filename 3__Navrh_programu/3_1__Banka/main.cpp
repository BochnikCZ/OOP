#include <iostream>
#include <string>

#include "Bank.h"
using namespace std;

int main()
{
    Bank* MoneyBank = new Bank(5, 3);

    MoneyBank->CreateClient(0, "Rostislav Zelenka");
    MoneyBank->CreateAccount(0, MoneyBank->GetClient(0), 1.8);

    MoneyBank->GetAccount(0)->Deposit(1000);
    MoneyBank->AddInterest();

    MoneyBank->CreateClient(1, "Radovan Soucek");
    MoneyBank->CreateClient(2, "Vladimira Souckova");
    MoneyBank->CreateAccount(1, MoneyBank->GetClient(2), MoneyBank->GetClient(1), 2.1);

    MoneyBank->GetAccount(0)->Withdraw(200);
    MoneyBank->GetAccount(1)->Deposit(3000);

    MoneyBank->AddInterest();

    MoneyBank->GetAccount(0)->Withdraw(2000);
    MoneyBank->GetAccount(1)->Withdraw(2000);

    MoneyBank->Print();

    delete MoneyBank;

    return 0;
}