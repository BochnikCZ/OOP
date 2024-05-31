#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle
{
private:
	string type;
	int frame_size;
	int number_of_gears;

public:
	Bicycle(int ec, string ma, string mo, char s, double ppd, string t, int fs, int nog); //tested

	string GetType(); //tested
	int GetFrameSize(); //tested
	int GetNumberOfGears(); //tested
	void Print(); //tested
};