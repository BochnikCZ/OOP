#pragma once
#include <iostream>
using namespace std;

template<class T>
class BOX {
private:
	T* instance;

public:
	BOX(T* i);
	T* GetInstance();
};


template<class T>
BOX<T>::BOX(T* i) {
	this->instance = i;
}

template<class T>
T* BOX<T>::GetInstance() {
	return this->instance;
}
