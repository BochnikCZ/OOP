#pragma once
#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Client.h"

using namespace std;

class AbstractAccount
{
public:
	AbstractAccount();
	virtual ~AbstractAccount();

	virtual bool CanWithdraw(double a) = 0;
};

