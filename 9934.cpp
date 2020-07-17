#include <iostream>
using namespace std;

int k, tree[1024], limit = 1;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> k;
}

void InorderTraversal(int i)
{
	if (i >= limit)
		return;

	InorderTraversal(2 * i);
	cin >> tree[i];
	InorderTraversal(2 * i + 1);
}

void CreateTree()
{
	for (int i = 0; i < k; i++)
		limit *= 2;

	InorderTraversal(1);
}

void PrintTree()
{
	int levelLimit = 2, idx = 1;
	for (int i = 0; i < k; i++, levelLimit *= 2)
	{
		while (idx < levelLimit)
			cout << tree[idx++] << ' ';
		cout << '\n';
	}
}

int main(void)
{
	GetInput();
	CreateTree();
	PrintTree();
	return 0;
}