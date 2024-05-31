#pragma once
#include "RentRequest.h"

class RentalSystem
{
private:
	Client** clients;
	Vehicle** vehicles;
	RentRequest** requests;

	static int number_of_free_vehicles;
	static int number_of_vehicles_in_use;

	int max_vehicles;
	int max_clients;
	int max_requests;

public:
	RentalSystem(int max);
	~RentalSystem();

	static int GetNumberOfFreeVehicles();
	static int GetNumberOfVehiclesInUse();


	Client* CreateClient(int id, string n, int a, bool dl);

	Car* RegisterVehicle(int ec, string ma, string mo, double ppd, double tc, string lp, string bs, int y);
	Motorcycle* RegisterVehicle(int evc, string ma, string mo, double ppd, double tc, string lp, int enc, string bs, int nos);
	Bicycle* RegisterVehicle(int ec, string ma, string mo, double ppd, string t, int fs, int nog);
	RentRequest* CreateRequest(int rn, int d, Vehicle* v, Client* c);

	Client* SearchClient(int id);
	Vehicle* SearchVehicle(int ec);
	RentRequest* SearchRequest(int rn);

	void RemoveClient(int id);
	void RemoveVehicle(int ec);
	void RemoveRequest(int rn);

	void Print();
};