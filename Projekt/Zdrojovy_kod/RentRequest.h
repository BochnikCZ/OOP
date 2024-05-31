#pragma once
#include "Bicycle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Client.h"

class RentRequest
{
private:
	int request_number;
	int duration;
	Vehicle* vehicle;
	Client* client;
	double total_price;

	static int objectsCount;
	static double fuel_price;

public:
	RentRequest(int rn, int d, Vehicle* v, Client* c);

	~RentRequest();

	static int GetObjectsCountRequests();
	static double GetFuelPrice();

	int GetRequestNumber();
	int GetDuration();
	Vehicle* GetVehicle();
	Client* GetClient();
	double GetTotalPrice();
	void Print();
};