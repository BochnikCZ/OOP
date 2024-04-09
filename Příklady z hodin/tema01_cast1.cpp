#include <iostream>
using namespace std;

class KeyValue
{
private:
	int key;
	double value;
	KeyValue* next;
public:
	KeyValue(int k, double v);
	~KeyValue();
	int GetKey();
	double GetValue();
	KeyValue* GetNext();
	KeyValue* CreateNext(int k, double v);
};

KeyValue::KeyValue(int k, double v)
{
	this->key = k;
	this->value = v;
	this->next = nullptr;
}

KeyValue::~KeyValue()
{
	if (this->next != nullptr)
	{
		delete this->next;
		this->next = nullptr;
	}
}

int KeyValue::GetKey()
{
	return this->key;
}

double KeyValue::GetValue()
{
	return this->value;
}

KeyValue* KeyValue::GetNext()
{
	return this->next;
}

KeyValue* KeyValue::CreateNext(int k, double v)
{
	this->next = new KeyValue(k, v);
	return this->next;
}

int main()
{
	KeyValue* kv1 = new KeyValue(1, 1.5);
	cout << kv1->CreateNext(2, 2.5)->GetKey() << endl;
	
	KeyValue* kv2 = kv1->GetNext();
	cout << kv2->GetNext() << endl;
	
	delete kv1;
	//delete kv2;

	cout << kv1->GetKey() << endl;			
	//jestli�e sma�eme n�co z pam�ti, u� je to nav�dy nedostupn�, a proto se n�m p�i kompilaci tohoto k�du vyp�e random nesmysln� ��slo m�sto p�vodn�ho kl��e objektu kv1
	cout << kv2->GetKey() << endl;

	getchar();
	return 0;
}
