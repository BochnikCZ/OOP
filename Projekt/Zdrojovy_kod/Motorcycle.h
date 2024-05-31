#pragma once
#include "MotorVehicle.h"

class Motorcycle : public MotorVehicle
{
private:
	int engine_capacity;
	string body_style;
	int number_of_seats;
public:
	Motorcycle(int evc, string ma, string mo, char s, double ppd, double tc, string lp, int enc, string bs, int nos); //tested
	int GetEngineCapacity(); //tested
	string GetBodyStyle(); //tested
	int GetNumberOfSeats(); //tested
	bool ConditionsCheck(int a, bool dl); //tested all scenarios
	void Print(); //tested
};