#include "RentalSystem.h"

double RentalSystem::fuel_price = 38.50;
double RentalSystem::GetFuelPrice()
{
	return RentalSystem::fuel_price;
}

//////////////////////////////////////////////
// Statistika o vozidlech v rùzných stavech //
//////////////////////////////////////////////
int RentalSystem::number_of_free_vehicles = 0;
//int RentalSystem::number_of_reserved_vehicles = 0;
int RentalSystem::number_of_vehicles_in_use = 0;
int RentalSystem::GetNumberOfFreeVehicles() {}
int RentalSystem::GetNumberOfVehiclesInUse() {}
void MakeDailyStats() {}



/////////////////////////////
// Konstruktor, destruktor //
/////////////////////////////
RentalSystem::RentalSystem(int max_vehicles)
{
	this->clients = new Client * [max_vehicles * 2];
	this->vehicles = new Vehicle * [max_vehicles];
	this->requests = new RentRequest * [max_vehicles * 2];
}
RentalSystem::~RentalSystem()
{
	int i;
	while (Client::GetObjectsCountClient() != 0)
	{
		i = Client::GetObjectsCountClient();
		i -= 1;
		delete this->clients[i];
	}
	delete[] this->clients;

	while (Vehicle::GetObjectsCountVehicles() != 0)
	{
		i = Vehicle::GetObjectsCountVehicles();
		i -= 1;
		delete this->vehicles[i];
	}
	delete[] this->vehicles;

	while (RentRequest::GetObjectsCountRequests() != 0)
	{
		i = RentRequest::GetObjectsCountRequests();
		i -= 1;
		delete this->requests[i];
	}
	delete[] this->requests;
}

///////////////////////////////////////
// Vytvoøit klienta/vozidlo/požadavek//
///////////////////////////////////////
Client* RentalSystem::CreateClient(int id, string n, int a, bool dl)
{
	Client* client = new Client(id, n, a, dl);
	this->clients[Client::GetObjectsCountClient() - 1] = client;
	return this->clients[Client::GetObjectsCountClient() - 1];
}
Car* RentalSystem::RegisterVehicle(string lp, string ma, string mo, int y, string bs, double rp, double tc)
{
	Car* vehicle = new Car(lp, ma, mo, y, bs, rp, tc, 'F');
	this->vehicles[Vehicle::GetObjectsCountVehicles() - 1] = vehicle;
	RentalSystem::number_of_free_vehicles += 1;
	return vehicle;
}
//!!!!!!!!!!!!!!!!!!!!!!!!
RentRequest* RentalSystem::CreateRequest(int rn, int d, Car* v, Client* c) 
{
	if (c->GetAge() < 18 )
	{
		cout << "Error: in order to drive car, you have to be 18 or more." << endl;
		return nullptr;
	}
	if (c->GetLicence() == false)
	{
		cout << "Error: in order to drive a car, you have to have driving licence." << endl;
		return nullptr;
	}
	if (v->GetStatus() != 'F')
	{
		cout << "Error: this vehicle is not available at the moment." << endl;
	}
	RentRequest* request = new RentRequest(rn, d, v, c);
	this->requests[RentRequest::GetObjectsCountRequests() - 1] = request;
	
	//MAKE STATS??
	
	return this->requests[RentRequest::GetObjectsCountRequests() - 1];
}



/////////////////////////////////////
// Hledat klienta/vozidlo/požadavek//
/////////////////////////////////////
Client* RentalSystem::GetClient(int id) 
{
	for (int i = 0; i < Client::GetObjectsCountClient(); i++)
	{
		if (this->clients[i]->GetID() == id)
		{
			return this->clients[i];
		}
	}
	cout << "Client not found in system database..." << endl;
	return nullptr;
}
Vehicle* RentalSystem::GetVehicle(string ec) 
{
	for (int i = 0; i < Vehicle::GetObjectsCountVehicles(); i++)
	{
		if (this->vehicles[i]->GetEvidenceCode() == ec)
		{
			return this->vehicles[i];
		}
	}
	cout << "Vehicle not found in system database..." << endl;
	return nullptr;
}
RentRequest* RentalSystem::GetRequest(int rn)
{
	for (int i = 0; i < RentRequest::GetObjectsCountRequests(); i++)
	{
		if (this->requests[i]->GetRequestNumber() == rn)
		{
			return this->requests[i];
		}
	}
	cout << "Request not found in system database..." << endl;
	return nullptr;
}

////////////////////////////////////////////////////////////
// Mazání klienta/vozidla/požadavku ze systémové databáze //
////////////////////////////////////////////////////////////
Client* RentalSystem::RemoveClient(int id)
{
	int i = 0;
	int x = Client::GetObjectsCountClient();
	Client* deleted_client;
	for (; i < x; i++)
	{
		if (this->clients[i]->GetID() == id)
		{
			deleted_client = this->clients[i];
			delete this->clients[i];
			this->clients[i] = nullptr;
			break;
		}
	}
	for (; i < x; i++)
	{
		int j = i + 1;
		this->clients[i] = this->clients[j];
		this->clients[j] = nullptr;
	}
	this->clients[x] = nullptr;
	return deleted_client;
}

Car* RentalSystem::RemoveVehicle(string ec)
{
	int i = 0;
	int x = Vehicle::GetObjectsCountVehicle();
	Client* deleted_client;
	for (; i < x; i++)
	{
		if (this->clients[i]->GetID() == id)
		{
			deleted_client = this->clients[i];
			delete this->clients[i];
			this->clients[i] = nullptr;
			break;
		}
	}
	for (; i < x; i++)
	{
		int j = i + 1;
		this->clients[i] = this->clients[j];
		this->clients[j] = nullptr;
	}
	this->clients[x] = nullptr;
	return deleted_client;
}
RentRequest* RentalSystem::RemoveRequest(int rn)
{

}