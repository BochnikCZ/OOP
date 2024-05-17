#pragma once
#include <iostream>
#include "Client.h"
#include "Car.h"
#include "RentRequest.h"

using namespace std;

class RentalSystem
{
private:
	Client** clients;
	Vehicle** vehicles;
	RentRequest** requests;

	static int number_of_free_vehicles;
	//static int number_of_reserved_vehicles;
	static int number_of_vehicles_in_use;

	static double fuel_price;

public:
	RentalSystem(int max_vehicles);
	~RentalSystem();

	static double GetFuelPrice();
	static int GetNumberOfFreeVehicles();
	//static int GetNumberOfFreeVehicles();
	static int GetNumberOfVehiclesInUse();

	Client* CreateClient(int id, string n, int a, bool dl);
	Car* RegisterVehicle(string lp, string ma, string mo, int y, string bs, double rp, double tc);
	//Motorbike* RegisterVehicle();
	//Bicycle* RegisterVehicle();
	RentRequest* CreateRequest(int rn, int d, Car* v, Client* c);
	//RentRequest* CreateRequest(int rn, int d, Motorbike* v, Client* c);
	//RentRequest* CreateRequest(itn rn, int d, Bicycle* v, Client* c);

	Client* GetClient(int id);
	Car* GetVehicle(string ec);
	RentRequest* GetRequest(int rn);

	Client* RemoveClient(int id);
	Car* RemoveVehicle(string ec);
	RentRequest* RemoveRequest(int rn);

};