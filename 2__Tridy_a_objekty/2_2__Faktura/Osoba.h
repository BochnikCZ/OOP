#pragma once
#include <iostream>
#include <string>

using namespace std;

class Osoba
{
private:
    string Jmeno;
    string Prijmeni;
    string Adresa;

public:
    Osoba(string jmeno, string prijmeni, string adresa);
    string GetFirstName();
    string GetLastName();
    string GetAddress();
};
