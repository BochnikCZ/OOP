#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "AbstractAccount.h"

using namespace std;


AbstractAccount::AbstractAccount()
{
	cout << "AbstractAccount constructor" << endl;
}

AbstractAccount::~AbstractAccount()
{
	cout << "AbstractAccount destructor" << endl;
}