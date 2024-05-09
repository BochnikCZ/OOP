#pragma once
#include <iostream>
#include <string>
#include "Osoba.h"
#include "Polozka.h"

using namespace std;

class Faktura
{
private:
    int Cislo;
    Osoba* Prijemce;
    int PocetPolozek;
    int MaxPolozek;
    Polozka** Polozky;

public:
    Faktura(int cislo, Osoba* prijemce, int max_polozek);
    ~Faktura();
    bool PridatPolozku(string nazev, double cena);
    Polozka* OdebratPolozku(string nazev);
    double SpocitatCenu();
    void Vytisknout();
};
