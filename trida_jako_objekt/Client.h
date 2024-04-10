#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.cpp"
#include "Account.h"
#include "Bank.h"

using namespace std;



class Client
{
private:
	int code;
	string name;
	static int ObjectsCount;


public:
	Client(int code, string name);

	int GetCode();
	string GetName();
	static int GetObjectsCount();

};