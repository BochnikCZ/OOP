#pragma once
#include "Vehicle.h"

class MotorVehicle : public Vehicle
{
private:
	double tank_capacity;
	string licence_plate;
public:
	MotorVehicle(int ec, string ma, string mo, char s, double ppd, double tc, string lp);

	double GetTankCapacity();
	string GetLicencePlate();
	double CalculateTotalPrice(int d, double fp);
};