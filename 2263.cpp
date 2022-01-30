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

int n;
vector<int> inOrder, postOrder;
Tree nodes[100000];

void GetInput1()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
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
	GetTraversalInput(inOrder);
	GetTraversalInput(postOrder);
}

void PreOrderTraversal(Tree * tree)
{
	cout << tree->value << ' ';
	if (tree->left != NULL)
		PreOrderTraversal(tree->left);
	if (tree->right != NULL)
		PreOrderTraversal(tree->right);
}

Tree * CreateTree(const int begin, const int end, int rightChild)
{
	if (begin == end)
		return nullptr;

	Tree * root = &nodes[end - 1];
	root->init(postOrder[end - 1]);

	const int offset = (find(inOrder.begin(), inOrder.end(), root->value) - inOrder.begin()) - (end - 1) - rightChild;

	root->left = CreateTree(begin, end - 1 + offset, rightChild);
	root->right = CreateTree(end - 1 + offset, end - 1, rightChild + 1);

	return root;
}

int main(void)
{
	GetInput1();
	GetInput2();
	Tree * tree = CreateTree(0, postOrder.size(), 0);
	PreOrderTraversal(tree);
	cout << '\n';
	return 0;
}