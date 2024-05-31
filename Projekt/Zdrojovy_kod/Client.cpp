#include "Client.h"

int Client::objectsCount = 0;

Client::Client(int id, string n, int a, bool dl)
{
	this->id = id;
	this->name = n;
	this->age = a;
	this->driving_licence = dl;

	Client::objectsCount += 1;
	cout << "New Client object has just been made..." << endl;
}

Client::~Client()
{
	Client::objectsCount -= 1;
	cout << "A Client object has been removed..." << endl;
}

int Client::GetObjectsCountClient()
{
	return Client::objectsCount;
}

int Client::GetID()
{
	return this->id;
}

string Client::GetName()
{
	return this->name;
}

int Client::GetAge()
{
	return this->age;
}

bool Client::GetLicence()
{
	return this->driving_licence;
}
void Client::Print()
{
	cout << "Client information" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "ID: " << this->GetID() << endl;
	cout << "Name: " << this->GetName() << endl;
	cout << "Driving licence: " << this->GetLicence() << endl;
}