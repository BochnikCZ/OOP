#pragma once

#include <iostream>
#include <string.h>
#include <stdbool.h>


using namespace std;



class Client
{
private:
	static int objectsCountClient;
	int code;
	string name;


public:
	static int GetObjectsCountClient();

	Client(int code, string name);
	~Client();

	int GetCode();
	string GetName();
};