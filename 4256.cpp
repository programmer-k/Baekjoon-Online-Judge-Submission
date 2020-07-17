#include <iostream>
#include <vector>
using namespace std;

class Tree
{
public:
	int value;
	Tree * left;
	Tree * right;
	Tree(int value)
	{
		this->value = value;
		this->left = this->right = NULL;
	}
};

int t, n;
vector<int> preOrder, inOrder;

void GetInput1()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
}

void GetTraversalInput(vector<int>& vec)
{
	vec.clear();
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
}

void GetInput2()
{
	preOrder.clear();
	inOrder.clear();

	cin >> n;
	GetTraversalInput(preOrder);
	GetTraversalInput(inOrder);
}

void PostOrderTraversal(Tree * tree)
{
	if (tree->left != NULL)
		PostOrderTraversal(tree->left);
	if (tree->right != NULL)
		PostOrderTraversal(tree->right);
	cout << tree->value << ' ';
}

Tree * CreateTree(int preOrderIndex, int size)
{
	cout << "CreateTree(" << preOrderIndex << ", " << size << ')' << endl;

	if (size == 0)
		return NULL;

	Tree * root = new Tree(preOrder[preOrderIndex]);
	preOrder.erase(preOrder.begin() + preOrderIndex);

	if (size > 1)
	{
		int inOrderIndex = distance(inOrder.begin(), find(inOrder.begin(), inOrder.end(), root->value));
		root->left = CreateTree(preOrderIndex, inOrderIndex - preOrderIndex + 1);
		root->right = CreateTree(inOrderIndex + 1, size - 1 - (inOrderIndex - preOrderIndex + 1));
	}

	return root;
}

int main(void)
{
	GetInput1();
	for (int i = 0; i < t; i++)
	{
		GetInput2();
		Tree * tree = CreateTree(0, preOrder.size());
		PostOrderTraversal(tree);
		cout << '\n';
	}
	return 0;
}