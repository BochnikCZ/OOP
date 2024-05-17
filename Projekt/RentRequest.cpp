#include "RentRequest.h"

int RentRequest::objectsCount = 0;

RentRequest::RentRequest(int rn, int d, Car* v, Client* c)
{
	this->request_number = rn;
	this->duration = d;
	this->vehicle = v;
	this->client = c;
}
RentRequest::~RentRequest(){}

int RentRequest::GetObjectsCountRequests()
{
	return RentRequest::objectsCount;
}

int RentRequest::GetRequestNumber()
{
	return this->request_number;
}
Date* RentRequest::GetRentStart()
{
	return this->rent_start;
}
Date* RentRequest::GetRentEnd()
{
	return this->rent_end;
}
double RentRequest::GetTotalPrice(int duration)
{
	return this->total_price;
}