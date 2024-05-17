#pragma once
#include <iostream>

using namespace std;

class Vehicle
{
private:
	string evidence_code;
	string make;
	string model;

	char status;				//'R' - reserved, 'F' - free, 'U' - in use

	static int objectsCount;
protected:
	double rental_price;
public:

	Vehicle(string ec, string ma, string mo, char s);
	~Vehicle();

	static int GetObjectsCountVehicles();

	string GetEvidenceCode();
	string GetMake();
	string GetModel();
	char GetStatus();
	char SetStatus(char s);
	
	virtual double CalculatePrice(int duration);
};