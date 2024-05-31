#include "RentalSystem.h"

int RentalSystem::number_of_free_vehicles = 0;
int RentalSystem::number_of_vehicles_in_use = 0;

int RentalSystem::GetNumberOfFreeVehicles()
{
	return RentalSystem::number_of_free_vehicles;
}
int RentalSystem::GetNumberOfVehiclesInUse()
{
	return RentalSystem::number_of_vehicles_in_use;
}


RentalSystem::RentalSystem(int max)
{
	this->vehicles = new Vehicle * [max];

	int x = max_vehicles * 2;
	this->clients = new Client * [x];
	this->requests = new RentRequest * [x];

	this->max_vehicles = max;
	this->max_clients = max * 2;
	this->max_requests = max * 2;
}
RentalSystem::~RentalSystem()
{
	
	for (int i = 0; i < this->max_requests; i++)
	{
		if (this->requests[i] != nullptr)
		{
			delete this->requests[i];
		}
	}
	

	for (int j = 0; j < this->max_clients; j++)
	{
		if (this->clients[j] != nullptr)
		{
			delete this->clients[j];
		}
	}

	for (int k = 0; k < this->max_vehicles; k++)
	{
		if (this->vehicles[k] != nullptr)
		{
			delete this->vehicles[k];
		}
	}

	delete[] this->clients;
	delete[] this->vehicles;
	delete[] this->requests;
}

Client* RentalSystem::CreateClient(int id, string n, int a, bool dl)
{
	if (Client::GetObjectsCountClient() >= this->max_clients)
	{
		cout << "We're sorry, but our system can't accept a new client at the moment. Please, try again later." << endl;
		return nullptr;
	}

	Client* client = new Client(id, n, a, dl);
	this->clients[Client::GetObjectsCountClient() - 1] = client;
	return this->clients[Client::GetObjectsCountClient() - 1];
}

Car* RentalSystem::RegisterVehicle(int ec, string ma, string mo, double ppd, double tc, string lp, string bs, int y)
{
	if (Vehicle::GetObjectsCountVehicles() >= max_vehicles)
	{
		cout << "Error: Not enough space for another vehicle." << endl;
		return nullptr;
	}
	Car* vehicle = new Car(ec, ma, mo, 'F', ppd, tc, lp, bs, y);
	this->vehicles[Vehicle::GetObjectsCountVehicles() - 1] = vehicle;
	RentalSystem::number_of_free_vehicles += 1;
	return vehicle;
}
Motorcycle* RentalSystem::RegisterVehicle(int evc, string ma, string mo, double ppd, double tc, string lp, int enc, string bs, int nos)
{
	if (Vehicle::GetObjectsCountVehicles() >= max_vehicles)
	{
		cout << "Error: Not enough space for another vehicle." << endl;
		return nullptr;
	}
	Motorcycle* vehicle = new Motorcycle(evc, ma, mo, 'F', ppd, tc, lp, enc, bs, nos);
	this->vehicles[Vehicle::GetObjectsCountVehicles() - 1] = vehicle;
	RentalSystem::number_of_free_vehicles += 1;
	return vehicle;
}
Bicycle* RentalSystem::RegisterVehicle(int ec, string ma, string mo, double ppd, string t, int fs, int nog)
{
	if (Vehicle::GetObjectsCountVehicles() >= max_vehicles)
	{
		cout << "Error: Not enough space for another vehicle." << endl;
		return nullptr;
	}
	Bicycle* vehicle = new Bicycle(ec, ma, mo, 'F', ppd, t, fs, nog);
	this->vehicles[Vehicle::GetObjectsCountVehicles() - 1] = vehicle;
	RentalSystem::number_of_free_vehicles += 1;
	return vehicle;
}

RentRequest* RentalSystem::CreateRequest(int rn, int d, Vehicle* v, Client* c)
{
	if (RentRequest::GetObjectsCountRequests() >= this->max_requests)
	{
		cout << "We're sorry, but our system can't take a new rent request at the moment. Please, try again later." << endl;
		return nullptr;
	}

	RentRequest* request = new RentRequest(rn, d, v, c);
	this->requests[RentRequest::GetObjectsCountRequests() - 1] = request;
	RentalSystem::number_of_free_vehicles -= 1;
	RentalSystem::number_of_vehicles_in_use += 1;
	return request;
}

Client* RentalSystem::SearchClient(int id)
{
	const int x = Client::GetObjectsCountClient();
	for (int i = 0; i < x; i++)
	{
		if (this->clients[i]->GetID() == id)
		{
			cout << "Client found on index: " << i << endl;
			return this->clients[i];
		}
	}
	cout << "Client was not found in the system database." << endl;
	return nullptr;
}
Vehicle* RentalSystem::SearchVehicle(int ec)
{
	const int x = Vehicle::GetObjectsCountVehicles();
	for (int i = 0; i < x; i++)
	{
		if (this->vehicles[i]->GetEvidenceCode() == ec)
		{
			cout << "Vehicle found on index: " << i << endl;
			return this->vehicles[i];
			break;
		}
	}
	cout << "Vehicle was not found in the system database." << endl;
	return nullptr;
}

RentRequest* RentalSystem::SearchRequest(int rn)
{
	const int x = RentRequest::GetObjectsCountRequests();
	for (int i = 0; i < x; i++)
	{
		if (this->requests[i]->GetRequestNumber() == rn)
		{
			cout << "Request found on index: " << i << endl;
			return this->requests[i];
			break;
		}
	}
	cout << "Request was not found in the system database." << endl;
	return nullptr;
}

void RentalSystem::RemoveClient(int id)
{
	const int x = Client::GetObjectsCountClient();
	Client* selected_client = nullptr;
	for (int i = 0; i < x; i++)
	{
		if (this->clients[i]->GetID() == id)
		{
			selected_client = this->clients[i];
			for (int j = i; j < (x - 1); j++)
			{
				this->clients[j] = nullptr;
				this->clients[j] = this->clients[j + 1];
			}
			this->clients[x - 1] = nullptr;
			delete selected_client;
			cout << "A Client object has been removed entirely." << endl;
			return;
		}
	}

	cout << "Error: the Client object could not be removed." << endl;
	return;
}

void RentalSystem::RemoveVehicle(int ec)
{
	const int x = Vehicle::GetObjectsCountVehicles();
	Vehicle* selected_vehicle = nullptr;
	for (int i = 0; i < x; i++)
	{
		if (this->vehicles[i]->GetEvidenceCode() == ec)
		{
			selected_vehicle = this->vehicles[i];
			for (int j = i; j < (x - 1); j++)
			{
				this->vehicles[j] = nullptr;
				this->vehicles[j] = this->vehicles[j + 1];
			}
			this->vehicles[x - 1] = nullptr;
			if (selected_vehicle->GetStatus() == 'F')
			{
				RentalSystem::number_of_free_vehicles -= 1;
			}
			else if (selected_vehicle->GetStatus() == 'U')
			{
				RentalSystem::number_of_vehicles_in_use -= 1;
			}
			delete selected_vehicle;
			cout << "A Vehicle object has been removed entirely." << endl;
			return;
		}
	}

	cout << "Error: the Vehicle object could not be removed." << endl;
	return;
}

void RentalSystem::RemoveRequest(int rn)
{
	const int x = RentRequest::GetObjectsCountRequests();
	RentRequest* selected_request = nullptr;
	for (int i = 0; i < x; i++)
	{
		if (this->requests[i]->GetRequestNumber() == rn)
		{
			selected_request = requests[i];
			for (int j = i; j < (x-1); j++)
			{
				this->requests[j] = nullptr;
				this->requests[j] = this->requests[j + 1];
			}
			this->requests[x - 1] = nullptr;
			selected_request->GetVehicle()->SetStatus('F');
			delete selected_request;
			RentalSystem::number_of_free_vehicles += 1;
			RentalSystem::number_of_vehicles_in_use -= 1;
			cout << "A RentRequest object has been removed entirely." << endl;
			return;

		}
	}
	cout << "Error: the RentRequest object could not be removed." << endl;
	return;
}

void RentalSystem::Print()
{
	cout << "Database printout: " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Maximal client database capacity: " << this->max_clients << endl;
	cout << "Current number of clients in the database: " << Client::GetObjectsCountClient() << endl;
	printf("\n");
	cout << "Maximal vehicle database capacity: " << this->max_vehicles << endl;
	cout << "Current number of vehicles in the database: " << Vehicle::GetObjectsCountVehicles() << endl;
	printf("\n");
	cout << "Maximal active requests database capacity: " << this->max_requests << endl;
	cout << "Current number of rent requests in the database: " << RentRequest::GetObjectsCountRequests() << endl;
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < Client::GetObjectsCountClient(); i++)
	{
		this->clients[i]->Print();
	}
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < Vehicle::GetObjectsCountVehicles(); i++)
	{
		this->vehicles[i]->Print();
	}
	cout << "-----------------------------------------" << endl;
	cout << "Active rent requests:" << endl;
	for (int i = 0; i < RentRequest::GetObjectsCountRequests(); i++)
	{
		this->requests[i]->Print();
		printf("\n");
	}
}