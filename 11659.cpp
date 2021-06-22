#include <iostream>
using namespace std;

int n, m, nums[100000], prefixSum[100001];

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
}

void CalcPrefixSum()
{
	for (int i = 1; i <= n; i++)
		prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
}

void Solve()
{
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		cout << prefixSum[end] - prefixSum[start - 1] << '\n';
	}
}

int main(void)
{
	GetInput();
	CalcPrefixSum();
	Solve();
	return 0;
}