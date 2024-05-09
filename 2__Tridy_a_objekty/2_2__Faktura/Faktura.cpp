#include <iostream>
#include <string>
#include "Faktura.h"

Faktura::Faktura(int cislo, Osoba* prijemce, int max_polozek)
{
    this->Cislo = cislo;
    this->Prijemce = prijemce;
    this->PocetPolozek = 0;
    this->MaxPolozek = max_polozek;
    this->Polozky = new Polozka * [max_polozek];
}

Faktura::~Faktura()
{
    for (int i = 0; i < this->PocetPolozek; i++)
    {
        delete this->Polozky[i];
    }
    delete[] this->Polozky;
}

bool Faktura::PridatPolozku(string nazev, double cena)
{
    if (this->PocetPolozek < this->MaxPolozek)
    {
        Polozka* polozka = new Polozka(nazev, cena);
        this->Polozky[this->PocetPolozek] = polozka;
        this->PocetPolozek++;
        return true;
    }
    else
    {
        return false;
    }
}

Polozka* Faktura::OdebratPolozku(string nazev)
{
    for (int i = 0; i < this->PocetPolozek; i++)
    {
        if (this->Polozky[i]->GetItemName() == nazev)
        {
            Polozka* odebranaPolozka = this->Polozky[i];
            for (int j = i; j < this->PocetPolozek - 1; j++)
            {
                this->Polozky[j] = this->Polozky[j + 1];
            }
            this->PocetPolozek--;
            return odebranaPolozka;
        }
    }
    return nullptr;
}

double Faktura::SpocitatCenu()
{
    double celkovaCena = 0;
    for (int i = 0; i < this->PocetPolozek; i++)
    {
        celkovaCena += this->Polozky[i]->GetPrize();
    }
    return celkovaCena;
}

void Faktura::Vytisknout()
{
    cout << "Cislo objednavky: " << this->Cislo << endl;
    cout << "Jmeno: " << this->Prijemce->GetFirstName() << endl;
    cout << "Prijmeni: " << this->Prijemce->GetLastName() << endl;
    cout << "Adresa doruceni: " << this->Prijemce->GetAddress() << endl;

    cout << "Objednane zbozi:" << endl;
    cout << endl;
    for (int i = 0; i < this->PocetPolozek; i++)
    {
        cout << "Typ zbozi" << endl;
        cout << this->Polozky[i]->GetItemName() << endl;
        cout << "Cena" << endl;
        cout << this->Polozky[i]->GetPrize() << endl;
        cout << endl;
    }
    cout << endl;
    cout << "Celkem:		" << this->SpocitatCenu() << endl;
    cout << endl;
}
