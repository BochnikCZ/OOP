#pragma once
#include <iostream>

using namespace std;

class Vehicle
{
private:
	int evidence_code;
	string make;
	string model;

	char status;				//'F' - free, 'U' - in use
	double price_per_day;

	static int objectsCount;
public:

	Vehicle(int ec, string ma, string mo, char s, double ppd); //tested
	virtual ~Vehicle(); //tested

	static int GetObjectsCountVehicles(); //tested

	int GetEvidenceCode(); //tested
	string GetMake(); //tested
	string GetModel(); //tested
	char GetStatus(); //tested
	char SetStatus(char ns); //tested
	double GetPricePerDay(); //tested
	virtual double CalculateTotalPrice(int d, double fp); //tested
	virtual bool ConditionsCheck(int a, bool dl); //tested
	virtual void Print(); //tested

};