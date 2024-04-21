#pragma once

#include <iostream>
#include <string>


using namespace std;



class Client
{
private:
	int code;
	string name;


public:
	Client(int code, string name);

	int GetCode();
	string GetName();
};