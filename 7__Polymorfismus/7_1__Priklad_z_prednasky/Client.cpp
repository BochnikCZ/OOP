#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.h"

using namespace std;

int Client::objectsCountClient = 0;

Client::Client(int code, string name)
{
	this->code = code;
	this->name = name;

	Client::objectsCountClient += 1;
}

Client::~Client()
{
	Client::objectsCountClient -= 1;
}

int Client::GetObjectsCountClient()
{
	return Client::objectsCountClient;
}

int Client::GetCode()
{
	return this->code;
}

string Client::GetName()
{
	return this->name;
}