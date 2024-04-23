#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;

void Demo01()
{
	BinaryTree* root = new BinaryTree(".");

	root->CreateLeft("Left");
	root->CreateRight("Right");

	root->GetLeft()->CreateLeft("Left");

	cout << "Pocet vrstev stromu: " << root->FindDepth() << endl;
}

void Demo02()
{
	BinaryTree* root = new BinaryTree(".");

	root->Grow(3);
	
	cout << "Pocet vrstev stromu: " << root->FindDepth() << endl;
}

int main()
{
	Demo01();
	//Demo02();
		

	return 0;

}