#pragma once
#include <iostream>
#include "A.h"

using namespace std;

class B :public A {
public:
	B(int v);
};

B::B(int v) : A(v) {
}