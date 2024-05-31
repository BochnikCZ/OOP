#include "Motorcycle.h"

Motorcycle::Motorcycle(int evc, string ma, string mo, char s, double ppd, double tc, string lp, int enc, string bs, int nos) : MotorVehicle(evc, ma, mo, s, ppd, tc, lp)
{
	this->engine_capacity = enc;
	this->body_style = bs;
	this->number_of_seats = nos;
	cout << "New Motorcycle object has just been made..." << endl;
}

int Motorcycle::GetEngineCapacity()
{
	return this->engine_capacity;
}
string Motorcycle::GetBodyStyle()
{
	return this->body_style;
}
int Motorcycle::GetNumberOfSeats()
{
	return this->number_of_seats;
}

bool Motorcycle::ConditionsCheck(int a, bool dl)
{
	if (a < 15)
	{
		cout << "Error: kids under 15 are not allowed to ride motorcycles of any kind." << endl;
		return false;
	}
	else if (15 <= a && a < 18)
	{
		if (dl == false)
		{
			cout << "Error: you are not allowed to drive a motorcycle without driving licence." << endl;
			return false;
		}
		else if (this->GetEngineCapacity() > 50)
		{
			cout << "Error: you can't drive such strong motorcycle unless you are 18 or more!" << endl;
			return false;
		}
	}

	if (dl == false)
	{
		cout << "Error: you are not allowed to drive a motorcycle without driving licence." << endl;
		return false;
	}

	if (this->GetStatus() != 'F')
	{
		cout << "Error: this vehicle is not available at the moment." << endl;
		return false;
	}
}

void Motorcycle::Print()
{
	cout << "Motorcycle information:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Evidence code: " << this->GetEvidenceCode() << endl;
	cout << "Make / Brand: " << this->GetMake() << endl;
	cout << "Model: " << this->GetModel() << endl;
	cout << "Status: " << this->GetStatus() << endl;
	cout << "Rent price per a day: " << this->GetPricePerDay() << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Licence plate: " << this->GetLicencePlate() << endl;
	cout << "Engine capacity: " << this->GetEngineCapacity() << endl;
	cout << "Tank capacity: " << this->GetTankCapacity() << endl;
	cout << "Body style: " << this->GetBodyStyle() << endl;
	cout << "Number of seats: " << this->GetNumberOfSeats() << endl;
}