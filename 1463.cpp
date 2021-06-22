#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[1000001];
const int maximum = 1234567890;

int main(void)
{
	cin >> n;

	dp[1] = 0;

	for (int i = 2; i <= 1000000; i++)
		dp[i] = min({ dp[i - 1], (i % 2 == 0 ? dp[i / 2] : maximum), (i % 3 == 0 ? dp[i / 3] : maximum) }) + 1;

	cout << dp[n];

	return 0;
}