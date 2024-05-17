#include "Vehicle.h"

int Vehicle::objectsCount = 0;

Vehicle::Vehicle(string ec, string ma, string mo, char s)
{
	this->evidence_code = ec;
	this->make = ma;
	this->model = mo;
	this->status = s;

	Vehicle::objectsCount += 1;
}
Vehicle::~Vehicle()
{
	Vehicle::objectsCount -= 1;
}

int Vehicle::GetObjectsCountVehicles()
{
	return Vehicle::objectsCount;
}

string Vehicle::GetEvidenceCode()
{
	return this->evidence_code;
}
string Vehicle::GetMake()
{
	return this->make;
}
string Vehicle::GetModel()
{
	return this->model;
}
char Vehicle::GetStatus()
{
	return this->status;
}
char Vehicle::SetStatus(char s)
{
	this->status = s;
}

double Vehicle::CalculatePrice(int duration)
{
	return (this->rental_price * duration);
}