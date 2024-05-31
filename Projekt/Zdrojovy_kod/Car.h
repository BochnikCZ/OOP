#pragma once
#include "MotorVehicle.h"

class Car : public MotorVehicle
{
private:
	string body_style;
	int year;

public:
	Car(int ec, string ma, string mo, char s, double ppd, double tc, string lp, string bs, int y); //tested

	string GetBodyStyle(); //tested
	int GetYear(); //tested
	bool ConditionsCheck(int a, bool dl); //tested all scenarios
	void Print(); //tested
};