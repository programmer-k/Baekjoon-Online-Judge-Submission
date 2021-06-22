#include <iostream>
#include <vector>
using namespace std;

unsigned int t, dp[1000001];
vector<int> input;
const long long divider = 1000000009;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int num;
		cin >> num;
		input.push_back(num);
	}
}

void Solve()
{
	dp[1] = 1, dp[2] = 2, dp[3] = 4;

	for (int i = 4; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % divider;

	for (unsigned int i = 0; i < input.size(); i++)
		cout << dp[input[i]] << '\n';
}

int main(void)
{
	GetInput();
	Solve();
	return 0;
}