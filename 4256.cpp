#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tree
{
public:
	int value;
	Tree * left;
	Tree * right;
	void init(int value)
	{
		this->value = value;
		this->left = this->right = NULL;
	}
};

int t, n;
vector<int> preOrder, inOrder;
Tree nodes[1000];

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

Tree * CreateTree(const int begin, const int end, int leftChild)
{
	if (begin == end)
		return nullptr;

	Tree * root = &nodes[begin];
	root->init(preOrder[begin]);

	const int offset = (find(inOrder.begin(), inOrder.end(), root->value) - inOrder.begin()) - begin + leftChild;

	root->left = CreateTree(begin + 1, begin + offset + 1, leftChild + 1);
	root->right = CreateTree(begin + offset + 1, end, leftChild);

	return root;
}

int main(void)
{
	GetInput1();
	for (int i = 0; i < t; i++)
	{
		GetInput2();
		Tree * tree = CreateTree(0, preOrder.size(), 0);
		PostOrderTraversal(tree);
		cout << '\n';
	}
	return 0;
}