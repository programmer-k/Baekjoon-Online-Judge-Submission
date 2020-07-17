#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n;
vector<pair<int, int>> nodes;
vector<int> graph[100001];
int parents[100001];

void GetInput()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		nodes.push_back(make_pair(num1, num2));
	}
}

void CreateGraph()
{
	for (unsigned int i = 0; i < nodes.size(); i++)
	{
		graph[nodes[i].first].push_back(nodes[i].second);
		graph[nodes[i].second].push_back(nodes[i].first);
	}
}

void CalculateParents()
{
	queue<int> toExamine;
	toExamine.push(1);

	while (!toExamine.empty())
	{
		int i = toExamine.front();
		toExamine.pop();

		for (unsigned int j = 0; j < graph[i].size(); j++)
			if (parents[graph[i][j]] == 0)
			{
				parents[graph[i][j]] = i;
				toExamine.push(graph[i][j]);
			}
	}
}

void PrintParents()
{
	for (int i = 2; i <= n; i++)
		cout << parents[i] << '\n';
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	GetInput();
	CreateGraph();
	CalculateParents();
	PrintParents();
	return 0;
}