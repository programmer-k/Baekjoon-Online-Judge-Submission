#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100][10001];

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> memoryInUse;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		memoryInUse.push_back(temp);
	}

	vector<int> costToDeactivate;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		costToDeactivate.push_back(temp);
	}

	for (int j = 0; j <= 10000; j++)
		if (j >= costToDeactivate[0])
			dp[0][j] = memoryInUse[0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (j >= costToDeactivate[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - costToDeactivate[i]] + memoryInUse[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	int answer = 1234567890;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 10000; j++)
			if (dp[i][j] >= m)
				answer = min(answer, j);

	cout << answer << endl;
	return 0;
}