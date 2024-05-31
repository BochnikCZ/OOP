#include "MotorVehicle.h"

MotorVehicle::MotorVehicle(int ec, string ma, string mo, char s, double ppd, double tc, string lp) : Vehicle(ec, ma, mo, s, ppd)
{
	this->tank_capacity = tc;
	this->licence_plate = lp;
}

double MotorVehicle::GetTankCapacity()
{
	return this->tank_capacity;
}

string MotorVehicle::GetLicencePlate()
{
	return this->licence_plate;
}

double MotorVehicle::CalculateTotalPrice(int d, double fp)
{
	double i = (this->GetPricePerDay() * d) + (this->GetTankCapacity() * fp);
	return i;
}
