#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "B.h"
#include "template.h"

using namespace std;

int main()
{
	A* a = new A(50);
	B* b = new B(100);

	BOX<A>* ta = new BOX<A>(b);
	BOX<B>* tb = new BOX<B>(b);

	cout << ta->GetInstance()->GetValue();
	cout << tb->GetInstance()->GetValue();

	delete ta;
	delete tb;

	delete a;
	delete b;

	getchar();
	return 0;
}