#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, parents[500001], distances[500001], totalDistance;
vector<int> tree[500001], leafNodes;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
}

void CalculateParentsAndLeafNodes()
{
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int parent = q.front();
		q.pop();

		for (unsigned int i = 0; i < tree[parent].size(); i++)
		{
			int child = tree[parent][i];
			if (parents[child] == 0)
			{
				parents[child] = parent;
				q.push(child);
			}
		}

		if (tree[parent].size() == 1)
			leafNodes.push_back(parent);
	}
}

int FindRoot(int node)
{
	if (node == 1)
		return 0;
	else if (distances[node] != 0)
		return distances[node];

	
	return distances[node] = FindRoot(parents[node]) + 1;
}

void CalculateDistanceFromLeafToRoot()
{
	for (unsigned int i = 0; i < leafNodes.size(); i++)
	{
		int leafNode = leafNodes[i];
		int distance = FindRoot(leafNode);
		totalDistance += distance;
	}
}

void PrintResult()
{
	if (totalDistance % 2 == 1)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

int main(void)
{
	GetInput();
	CalculateParentsAndLeafNodes();
	CalculateDistanceFromLeafToRoot();
	PrintResult();
	return 0;
}