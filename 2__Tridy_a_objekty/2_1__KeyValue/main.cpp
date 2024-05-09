#include <iostream>
#include "KeyValues.h"

using namespace std;

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