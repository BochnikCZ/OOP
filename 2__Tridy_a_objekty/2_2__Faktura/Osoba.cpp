#include <iostream>
#include <string>
#include "Osoba.h"

Osoba::Osoba(string jmeno, string prijmeni, string adresa)
{
    this->Jmeno = jmeno;
    this->Prijmeni = prijmeni;
    this->Adresa = adresa;
}

string Osoba::GetFirstName()
{
    return this->Jmeno;
}

string Osoba::GetLastName()
{
    return this->Prijmeni;
}

string Osoba::GetAddress()
{
    return this->Adresa;
}
