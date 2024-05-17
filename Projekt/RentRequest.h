#pragma once
#include <iostream>
#include "Date.h"
#include "Car.h"
#include "Client.h"

using namespace std;

class RentRequest
{
private:
	int request_number;
	
	int duration;
	Date* rent_start;
	Date* rent_end;

	Vehicle* vehicle;
	Client* client;

	double total_price;

	static int objectsCount;

public:
	RentRequest(int rn, int d, Car* v, Client* c);
	//RentRequest(int rn, int d, Motorcycle* v, Client* c);
	//RentRequest(int rn, int d, Bicycle* v, Client* c);

	~RentRequest();

	static int GetObjectsCountRequests();

	int GetRequestNumber();
	Date* GetRentStart();
	Date* GetRentEnd();
	double GetTotalPrice(int duration);
	
};