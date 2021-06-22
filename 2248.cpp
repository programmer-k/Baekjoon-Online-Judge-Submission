#include <iostream>
#include <string>
using namespace std;

int dp[32][32];

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, l;
	long long i;
	cin >> n >> l >> i;

	for (int j = 0; j < 32; j++)
		dp[0][j] = 1;

	for (int i = 1; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	string answer;

	while (true)
	{
		if (i > dp[n - 1][l])
		{
			answer += "1";
			i -= dp[n - 1][l];
			l--;
		}
		else
			answer += "0";


		n--;

		if (n == 0)
			break;
		else if (l == 0)
		{
			for (int k = 0; k < n; k++)
				answer += "0";
			break;
		}
	}


	/*for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 5; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}*/

	cout << answer << endl;

	return 0;
}