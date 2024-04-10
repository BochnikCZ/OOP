#include <iostream>

#include "StaticValue.h"


int StaticValue::value = 0;

void StaticValue::IncValue()
{
	StaticValue::value += 1;
}

int StaticValue::GetValue()
{
	return StaticValue::value;
}