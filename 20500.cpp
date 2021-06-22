#include <iostream>
#include <algorithm>
using namespace std;

long long n, divisor = 1000000007, dp[1516][3];

long long Solve(int param1, int param2)
{
	if (param1 == 0)
		return (param2 == 0) ? 1 : 0;

	if (dp[param1][param2] != -1)
		return dp[param1][param2];
	else
		return dp[param1][param2] = (Solve(param1 - 1, (param2 + 1) % 3) + Solve(param1 - 1, (param2 + 5) % 3)) % divisor;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < 1516; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = -1;

	cout << Solve(n - 1, 2) << '\n';

	return 0;
}