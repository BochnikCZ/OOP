#pragma once
#include <iostream>
#include <string>

using namespace std;

class BinaryTree
{
private:
	BinaryTree* left;
	BinaryTree* right;

	string value;

public:
	BinaryTree(string v);
	~BinaryTree();
	BinaryTree* GetLeft();
	BinaryTree* GetRight();
	string GetValue();

	BinaryTree* CreateLeft(string v);
	BinaryTree* CreateRight(string v);

	//void Print();									//nepovedlo se mi vymyslet implementaci

	int FindDepth();
	void Grow(int numberOfLayers);
};