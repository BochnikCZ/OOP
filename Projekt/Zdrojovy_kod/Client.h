#pragma once
#include <iostream>

using namespace std;

class Client
{
private:
	int id;
	string name;
	int age;
	bool driving_licence;
	static int objectsCount;

public:
	Client(int id, string n, int a, bool dl);
	~Client();

	static int GetObjectsCountClient();

	int GetID();
	string GetName();
	int GetAge();
	bool GetLicence();
	void Print();
};