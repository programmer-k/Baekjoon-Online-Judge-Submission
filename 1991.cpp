#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	char data = 'A';
	Node * nodes[26];
	for (int i = 0; i < n; i++)
	{
		nodes[i] = new Node();
	}
}

class Tree
{
private:
	Node * root;
public:
	Tree()
	{
		root = NULL;
	}


};

class Node
{
private:
	char data;
	Node * left;
	Node * right;
};