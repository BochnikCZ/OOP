#include "Date.h"

Date::Date(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
}

int Date::GetDay()
{
	return this->day;
}

int Date::GetMonth()
{
	return this->month;
}

int Date::GetYear()
{
	return this->year;
}

void Date::GetDate()
{
	GetDay();
	GetMonth();
	GetYear();
}