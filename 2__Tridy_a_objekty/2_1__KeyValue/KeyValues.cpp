#include "KeyValues.h"

KeyValues::KeyValues(int n)
{
    this->keyValues = new KeyValue * [n];
    this->count = 0;
}

KeyValues::~KeyValues()
{
    for (int i = 0; i < this->count; i++)
    {
        delete this->keyValues[i];
    }
    delete[] this->keyValues;
}

KeyValue* KeyValues::CreateObject(int k, double v)
{
    KeyValue* newObject = new KeyValue(k, v);

    this->keyValues[this->count] = newObject;
    this->count += 1;

    return newObject;
}

KeyValue* KeyValues::RemoveObject(int k)
{
    int i;
    int temp = this->count;
    for (i = 0; i < this->count; i++)
    {
        if (this->keyValues[i]->GetKey() == k)
        {
            this->count -= 1;
            break;
        }
    }
    if (count != temp)
    {
        KeyValue* removedObject = this->keyValues[i];
        for (; i < count; i++)
        {
            keyValues[i] = keyValues[i + 1];
        }
        keyValues[i] = nullptr;

        return removedObject;
    }
    return nullptr;
}

KeyValue* KeyValues::SearchObject(int k)
{
    for (int i = 0; i < this->count; i++)
    {
        if (this->keyValues[i]->GetKey() == k)
        {
            return this->keyValues[i];
        }
    }

    return nullptr;
}

int KeyValues::Count()
{
    return this->count;
}