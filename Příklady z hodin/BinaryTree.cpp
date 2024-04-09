#include <iostream>
using namespace std;

class BinaryTree
{
private:
	BinaryTree* Left;
	BinaryTree* Right;
	string value;

public:
	BinaryTree(string v);
	~BinaryTree();
	BinaryTree* GetLeft();
	BinaryTree* GetRight();
	string GetValue();
	BinaryTree* CreateLeft(string v);
	BinaryTree* CreateRight(string v);
	void Print();
	int FindDepth();
	void Grow(int numberOfLayers);

};

BinaryTree::BinaryTree(string v)
{
	this->value = v;
	this->Left = nullptr;
	this->Right = nullptr;
}

BinaryTree::~BinaryTree() {

	if (this->Right != nullptr) {
		delete this->Right;
		this->Right = nullptr;
	}
	if (this->Left != nullptr)
	{
		delete this->Left;
		this->Left = nullptr;
	}
}

BinaryTree* BinaryTree::GetLeft()
{
	return this->Left;
}

BinaryTree* BinaryTree::GetRight()
{
	return this->Right;
}

string BinaryTree::GetValue()
{
	return this->value;
}

BinaryTree* BinaryTree::CreateLeft(string v)
{
	this->Left = new BinaryTree(v);
	return this->Left;
}

BinaryTree* BinaryTree::CreateRight(string v)
{
	this->Right = new BinaryTree(v);
	return this->Right;
}

void BinaryTree::Print()
{

}

int BinaryTree::FindDepth()
{


}

void BinaryTree::Grow(int numberOfLayers)
{

}

int main()
{



	return 0;
}