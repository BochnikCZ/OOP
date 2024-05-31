#include "Bicycle.h"

Bicycle::Bicycle(int ec, string ma, string mo, char s, double ppd, string t, int fs, int nog) : Vehicle(ec, ma, mo, s, ppd)
{
	this->type = t;
	this->frame_size = fs;
	this->number_of_gears = nog;
	cout << "New Bicycle object has just been made..." << endl;
}

string Bicycle::GetType()
{
	return this->type;
}

int Bicycle::GetFrameSize()
{
	return this->frame_size;
}

int Bicycle::GetNumberOfGears()
{
	return this->number_of_gears;
}

void Bicycle::Print()
{
	cout << "Bicycle information:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Evidence code: " << this->GetEvidenceCode() << endl;
	cout << "Make / Brand: " << this->GetMake() << endl;
	cout << "Model: " << this->GetModel() << endl;
	cout << "Status: " << this->GetStatus() << endl;
	cout << "Rent price per a day: " << this->GetPricePerDay() << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Type: " << this->GetType() << endl;
	cout << "Frame size (in inches): " << this->GetFrameSize() << endl;
	cout << "Number of gears: " << this->GetNumberOfGears() << endl;
}