#include <iostream>
#include <string>

#include "Bank.h"
using namespace std;

void Demo1()
{
    Bank* MoneyBank = new Bank(4, 4);

    MoneyBank->CreateClient(0, "Tomas Novak");
    MoneyBank->CreateClient(1, "Anna Dvorakova");
    MoneyBank->CreateClient(2, "Radovan Soucek");
    MoneyBank->CreateClient(3, "Stanislav Zelenka");


    MoneyBank->CreateAccount(0, MoneyBank->GetClient(3), 0.041);                        //Typ ��tu: Account, bez partnera, bez creditu, s vlastn� (st�lou) �rokovou sazbou
    MoneyBank->GetAccount(0)->Deposit(100);
    cout << Account::GetObjectsCountAccount() << endl;
    MoneyBank->Print();
    getchar();

    MoneyBank->CreateAccount(1, MoneyBank->GetClient(0), MoneyBank->GetClient(1));      //Typ ��tu: PartnerAccount, s partnerem, bez creditu, s defaultn� �rokovou sazbou
    MoneyBank->GetAccount(1)->Deposit(100);

    MoneyBank->AddInterest();
    cout << Account::GetObjectsCountAccount() << endl;
    MoneyBank->Print();
    getchar();

    MoneyBank->CreateAccount(2, 35.99, MoneyBank->GetClient(2));                        //Typ ��tu: CreditAccount, bez partnera, s creditem, s defaultn� �rokovou sazbou
    MoneyBank->GetAccount(2)->Deposit(100);

    MoneyBank->ModifyInterestRate(0.076);
    MoneyBank->AddInterest();
    cout << Account::GetObjectsCountAccount() << endl;
    MoneyBank->Print();
    getchar();

    MoneyBank->CreateAccount(3, MoneyBank->GetClient(1));                               //Typ ��tu: Account, bez partnera, bez creditu, s defaultn� �rokovou sazbou
    MoneyBank->GetAccount(3)->Deposit(100);
    MoneyBank->AddInterest();
    cout << Account::GetObjectsCountAccount() << endl;
    MoneyBank->Print();
    getchar();
}

void Demo2()
{
    Client* o = new Client(0, "Smith");
    CreditAccount* ca = new CreditAccount(1, o, 1000);
    
    AbstractAccount* aa = ca;

    delete aa;
    delete o;

    getchar();
}




int main()
{

    //Demo1();            // Moje vlastn� demo
    Demo2();            // Demo z p�edn�ky


    return 0;
}