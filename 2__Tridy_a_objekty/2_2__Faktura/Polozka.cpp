#include <iostream>
#include <string>
#include "Polozka.h"

Polozka::Polozka(string nazev, double cena)
{
    this->Nazev = nazev;
    this->Cena = cena;
}

string Polozka::GetItemName()
{
    return this->Nazev;
}

double Polozka::GetPrize()
{
    return this->Cena;
}
