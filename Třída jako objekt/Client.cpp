#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.h"

using namespace std;

int Client::objectsCount = 0;

Client::Client(int code, string name)
{
	this->code = code;
	this->name = name;
	Client::objectsCount += 1;
}

Client::~Client()
{
	Client::objectsCount -= 1;
}

int Client::GetCode()
{
	return this->code;
}

string Client::GetName()
{
	return this->name;
}

int Client::GetObjectsCount()
{
	return Client::objectsCount;
}
