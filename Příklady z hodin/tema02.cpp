#include <iostream>
using namespace std;

class KeyValue
{
private:
    int key;
    double value;

public:
    KeyValue(int k, double v);
    int GetKey();
    double GetValue();
};

KeyValue::KeyValue(int k, double v)
{
    this->key = k;
    this->value = v;
}

int KeyValue::GetKey()
{
    return this->key;
}

double KeyValue::GetValue()
{
    return this->value;
}

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

int main()
{
    int N = 5;
    KeyValues* myKeyValues = new KeyValues(N);

    KeyValue* myKeyValue = myKeyValues->CreateObject(0, 0.5);
    cout << myKeyValue->GetValue() << endl;

    for (int i = 1; i < N; i++)
    {
        myKeyValues->CreateObject(i, (i + 0.5));
    }

    cout << myKeyValues->SearchObject(4)->GetValue() << endl;

    myKeyValues->RemoveObject(2);

    delete myKeyValues;

    //cout << myKeyValue->GetKey() << endl;

    getchar();
    return 0;
}