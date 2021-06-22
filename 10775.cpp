#include <iostream>
#include <set>
using namespace std;

int g, p, j;
int gates[100001];
set<int> inUse;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> g >> p;
	
	for (int i = 1; i <= p; i++)
		cin >> gates[i];

	for (int i = 1; i <= g; i++)
		inUse.insert(i);
}

void Solve()
{
	for (int i = 1; i <= p; i++)
	{
		if (inUse.empty())
			break;

		int gate = gates[i];
		set<int>::iterator it = inUse.lower_bound(gate);

		if (*inUse.begin() > gate)
			break;

		if (it == inUse.end() || *it > gate)
		{
			it--;
		}

		inUse.erase(*it);
	}
}

void Print()
{
	cout << g - inUse.size() << '\n';
}

int main(void)
{
	GetInput();
	Solve();
	Print();
	return 0;
}