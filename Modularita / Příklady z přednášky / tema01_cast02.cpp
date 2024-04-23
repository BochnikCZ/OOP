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
	KeyValue* DeleteAtPosition(int index);
	void GrowWithRecursion(int n);
	void GrowWithLoop(int n);
	
	void Print();
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

KeyValue* KeyValue::DeleteAtPosition(int index)
{
	if (index == 0) {
		KeyValue* temp = this->next;
		this->next = nullptr;
		return temp;
	}

	KeyValue* temp = this;
	for (int i = 0; i < index - 1; i++)
	{
		if (temp->next == nullptr) {
			return nullptr;
		}
		temp = temp->next;
	}

	KeyValue* deletedNode = temp->next;
	if (deletedNode == nullptr) {
		return nullptr;
	}

	temp->next = deletedNode->next;
	deletedNode->next = nullptr;

	return deletedNode;
}

void KeyValue::GrowWithLoop(int n)
{
	KeyValue* temp = this;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	for (int i = 0; i < n; i++)
	{
		temp->CreateNext(temp->GetKey() + 1, temp->GetValue() + 1);
		temp = temp->next;
	}
}

void KeyValue::Print()
{
	cout << "Key: " << this->key << ", value: " << this->value << endl;
	if (this->next == nullptr)
	{
		return;
	}
	else
	{
		this->next->Print();
	}
}

void KeyValue::GrowWithRecursion(int n)
{
	if (n <= 0) {
		return;
	}
	if (this->next == nullptr) {
		this->CreateNext(this->key + 1, this->value + 1);
	}
	if (this->next != nullptr) {
		this->next->GrowWithRecursion(n - 1);
	}
}


void Demo1()
{
	KeyValue* kv1 = new KeyValue(1, 1.5);
	kv1->CreateNext(2, 2.5);

	KeyValue* kv2 = kv1->GetNext();

	kv1->Print();

	kv1->~KeyValue();
	delete kv1;
}

void Demo2()
{
	KeyValue* kv1 = new KeyValue(1, 1.5);
	kv1->GrowWithLoop(3);
	kv1->DeleteAtPosition(1);

	kv1->Print();

	kv1->~KeyValue();
	delete kv1;

}

void Demo3()
{
	KeyValue* kv1 = new KeyValue(1, 1.5);
	kv1->GrowWithRecursion(5);
	kv1->Print();
	kv1->~KeyValue();
	delete kv1;
}
int main()
{
	//Demo1();
	//Demo2();
	Demo3();
	return 0;
}
