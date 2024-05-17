#pragma once
#include <iostream>
#include "Vehicle.h"
#include "RentalSystem.h"

using namespace std;

class Car : public Vehicle
{
private:
	string body_style;
	int year;
	double tank_capacity;

public:
	Car(string lp, string ma, string mo, int y, string bs, double rp, double tc, char s);
	
	string GetBodyStyle();
	int GetYear();
	double GetTankCapacity();

	double CalculatePrice(int duration);
};