#include "Vehicle.h"

int Vehicle::objectsCount = 0;

Vehicle::Vehicle(int ec, string ma, string mo, char s, double ppd)
{
	this->evidence_code = ec;
	this->make = ma;
	this->model = mo;
	this->status = s;
	this->price_per_day = ppd;

	Vehicle::objectsCount += 1;
	cout << "New Vehicle object has just been made..." << endl;

}
Vehicle::~Vehicle()
{
	Vehicle::objectsCount -= 1;
	cout << "A Vehicle object has been removed..." << endl;

}

int Vehicle::GetObjectsCountVehicles()
{
	return Vehicle::objectsCount;
}

int Vehicle::GetEvidenceCode()
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
	return this->status;
}
double Vehicle::GetPricePerDay()
{
	return this->price_per_day;
}

double Vehicle::CalculateTotalPrice(int d, double fp)
{
	return (this->GetPricePerDay() * d);
}
bool Vehicle::ConditionsCheck(int a, bool dl)
{
	if (this->GetStatus() != 'F')
	{
		cout << "Error: this vehicle is not available at the moment." << endl;
		return false;
	}

	return true;
}

void Vehicle::Print()
{
	cout << "Vehicle information:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Evidence code: " << this->GetEvidenceCode() << endl;
	cout << "Make / Brand: " << this->GetMake() << endl;
	cout << "Model: " << this->GetModel() << endl;
	cout << "Status: " << this->GetStatus() << endl;
	cout << "Rent price per a day: " << this->GetPricePerDay() << endl;
}