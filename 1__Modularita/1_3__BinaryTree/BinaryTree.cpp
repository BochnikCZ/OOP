#include "BinaryTree.h"

BinaryTree::BinaryTree(string v)
{
	this->value = v;
	this->left = nullptr;
	this->right = nullptr;
}

BinaryTree::~BinaryTree()
{
	if (this->left != nullptr)
	{
		delete this->left;
		this->left = nullptr;
	}

	else if (this->right != nullptr)
	{
		delete this->right;
		this->right = nullptr;
	}
}

BinaryTree* BinaryTree::GetLeft()
{
	return this->left;
}

BinaryTree* BinaryTree::GetRight()
{
	return this->right;
}

string BinaryTree::GetValue()
{
	return this->value;
}

BinaryTree* BinaryTree::CreateLeft(string v)
{
	this->left = new BinaryTree(v);
	return this->left;
}

BinaryTree* BinaryTree::CreateRight(string v)
{
	this->right = new BinaryTree(v);
	return this->right;
}
/*
void BinaryTree::Print()
{
																//nepovedlo se mi vymyslet implementaci
}
*/

int BinaryTree::FindDepth()
{
	int final = 0;
	int temp = 0;

	if (this->left == nullptr && this->right == nullptr)
	{
		final = 0;
	}

	if (this->left != nullptr)
	{
		temp = this->left->FindDepth();
		temp += 1;

		if (temp > final)
		{
			final = temp;
		}
	}
	if (this->right != nullptr)
	{
		temp = this->right->FindDepth();
		temp += 1;

		if (temp > final)
		{
			final = temp;
		}
	}
	return final;
}


void BinaryTree::Grow(int numberOfLayers)
{
	if (numberOfLayers == 0)
	{
		return;
	}
	else
	{
		int layers_left = numberOfLayers;
		int layers_right = numberOfLayers;

		this->CreateLeft("L");
		layers_left -= 1;
		if (layers_left != 0)
		{
			this->left->Grow(layers_left);
		}

		this->CreateRight("R");
		layers_right -= 1;
		if (layers_right != 0)
		{
			this->right->Grow(layers_right);
		}
	}
		return;
}