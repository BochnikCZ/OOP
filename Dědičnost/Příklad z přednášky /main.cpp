#include <iostream>
#include "StaticValue.h"

using namespace std;


int main()
{
	cout << StaticValue::GetValue() << endl;
	StaticValue::IncValue();
	cout << StaticValue::GetValue() << endl;

	StaticValue* sv = new StaticValue();
	cout << sv->GetValue() << endl;

	getchar();
	return 0;

}
