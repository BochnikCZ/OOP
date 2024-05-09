#pragma once
#include <iostream>
#include "KeyValue.h"

using namespace std;

class KeyValues
{
private:
    KeyValue** keyValues;
    int count;

public:
    KeyValues(int n);
    ~KeyValues();
    KeyValue* CreateObject(int k, double v);
    KeyValue* RemoveObject(int k);
    KeyValue* SearchObject(int key);
    int Count();
};