#include "Car.h"

Car::Car(string lp, string ma, string mo, int y, string bs, double rp, double tc, char s) : Vehicle(lp, ma, mo, s)
{
	this->year = y;
	this->body_style = bs;
	this->tank_capacity = tc;
}

string Car::GetBodyStyle()
{
	return this->body_style;
}
int Car::GetYear()
{
	return this->year;
}
double Car::GetTankCapacity()
{
	return this->tank_capacity;
}

double Car::CalculatePrice(int duration)
{
	double i = (this->tank_capacity * RentalSystem::GetFuelPrice()) + (this->rental_price * duration);
	return i;
}