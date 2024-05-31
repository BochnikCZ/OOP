#include "Car.h"

Car::Car(int ec, string ma, string mo, char s, double ppd, double tc, string lp, string bs, int y) : MotorVehicle(ec, ma, mo, s, ppd, tc, lp)
{
	this->body_style = bs;
	this->year = y;

	cout << "New Car object has just been made..." << endl;
}

string Car::GetBodyStyle()
{
	return this->body_style;
}
int Car::GetYear()
{
	return this->year;
}
bool Car::ConditionsCheck(int a, bool dl)
{
	if (a < 18)
	{
		cout << "Error: in order to drive car, you have to be 18 or more." << endl;
		return false;
	}
	if (dl == false)
	{
		cout << "Error: you are not allowed to drive a car without driving licence." << endl;
		return false;
	}
	if (this->GetStatus() != 'F')
	{
		cout << "Error: this vehicle is not available at the moment." << endl;
		return false;
	}

	return true;
}

void Car::Print()
{
	cout << "Car information:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Evidence code: " << this->GetEvidenceCode() << endl;
	cout << "Make / Brand: " << this->GetMake() << endl;
	cout << "Model: " << this->GetModel() << endl;
	cout << "Status: " << this->GetStatus() << endl;
	cout << "Rent price per a day: " << this->GetPricePerDay() << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Licence plate: " << this->GetLicencePlate() << endl;
	cout << "Body style: " << this->GetBodyStyle() << endl;
	cout << "Year of manufacture: " << this->GetYear() << endl;
	cout << "Tank capacity: " << this->GetTankCapacity() << endl;
}