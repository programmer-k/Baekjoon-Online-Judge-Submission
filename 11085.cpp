#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct info
{
	int s;
	int e;
	int val;
};

struct cmp
{
	bool operator()(info& a, info& b)
	{
		return a.val < b.val;
	}
};

int node, edge, start, dest, result, par[1001];
priority_queue<info, vector<info>, cmp> pq;

int find_par(int a)
{
	if (par[a] == a)
		return a;
	return par[a] = find_par(par[a]);
}

void uni(int a, int b)
{
	a = find_par(a);
	b = find_par(b);
	if (a < b)
		par[b] = a;
	else if (a > b)
		par[a] = b;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> node >> edge >> start >> dest;
	
	for (int i = 0; i < edge; i++)
	{
		info temp;
		cin >> temp.s >> temp.e >> temp.val;
		pq.push(temp);
	}

	for (int i = 0; i < node; i++)
		par[i] = i;

	while (!pq.empty())
	{
		int a = pq.top().s;
		int b = pq.top().e;
		int c = pq.top().val;
		pq.pop();

		if (find_par(start) == find_par(dest))
			break;

		int d = find_par(a);
		int e = find_par(b);
		if (d == e)
			continue;
		
		uni(a, b);
		result = c;
	}

	cout << result << '\n';
	return 0;
}