#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Faktura.h"

using namespace std;

int main()
{
    Osoba* zakaznik1 = new Osoba("Anna", "Dvorakova", "Kocourkov");
    Osoba* zakaznik2 = new Osoba("Tomas", "Skocdopole", "Tramtarie");
    Osoba* zakaznik3 = new Osoba("Jakub", "Nejezchleba", "Springfield");

    Polozka* zbozi1 = new Polozka("rozek", 3.50);
    Polozka* zbozi2 = new Polozka("maslo", 54.60);
    Polozka* zbozi3 = new Polozka("gothaj", 13.20);
    Polozka* zbozi4 = new Polozka("termix", 15.80);

    Faktura* objednavka1 = new Faktura(1, zakaznik1, 3);
    Faktura* objednavka2 = new Faktura(2, zakaznik2, 3);
    Faktura* objednavka3 = new Faktura(3, zakaznik3, 3);

    objednavka1->PridatPolozku(zbozi1->GetItemName(), zbozi1->GetPrize());

    objednavka2->PridatPolozku(zbozi1->GetItemName(), zbozi1->GetPrize());
    objednavka2->PridatPolozku(zbozi1->GetItemName(), zbozi1->GetPrize());
    objednavka2->PridatPolozku(zbozi2->GetItemName(), zbozi2->GetPrize());
    objednavka2->OdebratPolozku(zbozi1->GetItemName());

    objednavka3->PridatPolozku(zbozi3->GetItemName(), zbozi3->GetPrize());
    objednavka3->PridatPolozku(zbozi3->GetItemName(), zbozi3->GetPrize());
    objednavka3->OdebratPolozku(zbozi3->GetItemName());
    objednavka3->PridatPolozku(zbozi1->GetItemName(), zbozi1->GetPrize());

    objednavka1->Vytisknout();
    objednavka2->Vytisknout();
    objednavka3->Vytisknout();

    delete objednavka1;
    delete objednavka2;
    delete objednavka3;

    delete zbozi1;
    delete zbozi2;
    delete zbozi3;
    delete zbozi4;

    delete zakaznik1;
    delete zakaznik2;
    delete zakaznik3;

    return 0;
}
