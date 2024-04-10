#pragma once
#include <iostream>

class StaticValue
{
private:
	static int value;
	StaticValue();

public:
	static void IncValue();
	static int GetValue();
};