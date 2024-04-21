#pragma once

#include <iostream>
#include <string.h>
#include <stdbool.h>


using namespace std;



class Client
{
private:
	static int objectsCount;
	int code;
	string name;


public:
	Client(int code, string name);
	~Client();

	int GetCode();
	string GetName();
	static int GetObjectsCount();
};