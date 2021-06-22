#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[10001], dp[10001][501][2];

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			if (j != 1)
			{
				if (j)
				{
					dp[i][j][1] = dp[i - 1][j - 1][1] + arr[i];
					dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
				}
				else
				{
					dp[i][j][0] = max({ dp[i - 1][j + 1][0], dp[i - 1][j + 1][1], dp[i - 1][j][0] });
				}
			}
			else
			{
				dp[i][j][1] = max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0] + arr[i]);
				dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
			}
		}

	cout << dp[n][0][0];

	return 0;
}