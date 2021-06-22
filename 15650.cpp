#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> picks;

void Solve(int startNum, int pickLeft)
{
	if (pickLeft == 0)
	{
		for (unsigned int i = 0; i < picks.size(); i++)
			cout << picks[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = startNum; i <= n; i++)
	{
		picks.push_back(i);
		Solve(i + 1, pickLeft - 1);
		picks.pop_back();
	}
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	Solve(1, m);

	return 0;
}