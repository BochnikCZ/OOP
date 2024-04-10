#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.h"

using namespace std;

Client::Client(int code, string name)
{
	this->code = code;
	this->name = name;
}

int Client::GetCode()
{
	return this->code;
}

string Client::GetName()
{
	return this->name;
}
