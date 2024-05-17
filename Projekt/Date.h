#pragma once
#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(int d, int m, int y);

	int GetDay();
	int GetMonth();
	int GetYear();

	void GetDate();
};