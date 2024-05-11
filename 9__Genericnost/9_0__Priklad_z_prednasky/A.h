#pragma once
#include <iostream>
using namespace std;

class A
{
private:
	int value;

public:
	A(int v);
	int GetValue();
};

A::A(int v) {
	this->value = v;
}

int A::GetValue()
{
	return this->value;
}