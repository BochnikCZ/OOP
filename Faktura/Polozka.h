#pragma once
#include <iostream>
#include <string>

using namespace std;

class Polozka
{
private:
    string Nazev;
    double Cena;

public:
    Polozka(string nazev, double cena);
    string GetItemName();
    double GetPrize();
};
