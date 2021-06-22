#include <iostream>
using namespace std;

int n, m;
int table[1025][1025];
int prefixSum[1025][1025];

void GetInput()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> table[i][j];
}

void CalcPrefixSum()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + table[i][j];
}

void Solve()
{
	for (int i = 0; i < m; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << prefixSum[x2][y2] - prefixSum[x2][y1 - 1] - prefixSum[x1 - 1][y2] + prefixSum[x1 - 1][y1 - 1] << '\n';
	}
}

int main(void)
{
	GetInput();
	CalcPrefixSum();
	Solve();
	return 0;
}