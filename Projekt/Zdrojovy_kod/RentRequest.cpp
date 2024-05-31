#include "RentRequest.h"

int RentRequest::objectsCount = 0;
double RentRequest::fuel_price = 38.50;

RentRequest::RentRequest(int rn, int d, Vehicle* v, Client* c)
{
	this->request_number = rn;
	this->duration = d;
	this->vehicle = v;
	this->client = c;

	this->total_price = v->CalculateTotalPrice(d, RentRequest::GetFuelPrice());
	RentRequest::objectsCount += 1;
	cout << "A new Request object has been made..." << endl;
}

RentRequest::~RentRequest()
{
	RentRequest::objectsCount -= 1;
	cout << "A Request object has just been removed..." << endl;
}

int RentRequest::GetObjectsCountRequests()
{
	return RentRequest::objectsCount;
}
double RentRequest::GetFuelPrice()
{
	return RentRequest::fuel_price;
}

int RentRequest::GetRequestNumber()
{
	return this->request_number;
}
int RentRequest::GetDuration()
{
	return this->duration;
}
Vehicle* RentRequest::GetVehicle()
{
	return this->vehicle;
}
Client* RentRequest::GetClient()
{
	return this->client;
}
double RentRequest::GetTotalPrice()
{
	return this->total_price;
}

void RentRequest::Print()
{
	cout << "Rent request information: " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Request number: " << this->GetRequestNumber() << endl;
	cout << "Duration: " << this->GetDuration() << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;
	this->GetClient()->Print();
	cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;
	this->GetVehicle()->Print();
	cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;
	printf("\n");
	cout << "Total price: " << this->GetTotalPrice() << endl;
}