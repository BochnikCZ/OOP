#include "Client.h"

int Client::objectsCount = 0;

Client::Client(int id, string n, int a, bool dl)
{
	this->id = id;
	this->name = n;
	this->age = a;
	this->driving_licence = dl;

	Client::objectsCount += 1;
}

Client::~Client()
{
	Client::objectsCount -= 1;
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