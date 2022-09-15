#include <iostream>
using namespace std;

int n, k;
int coins[100];
int dp[2][10001];

// dp[i][j]는 동전을 i번째까지만 고려하고 동전의 합이 j일 때 경우의 수
// dp[i][j] = sum(dp[i - 1][j - val[i] * t]) (j - val[i] * t >= 0)
// dp[i][j] = dp[i][j - val[i]] + dp[i - 1][j]

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> coins[i];
}

void Solve()
{
    // i == 0
    for (int j = 0; j <= 10000; j++)
        dp[0][j] = (j % coins[0] == 0 ? 1 : 0);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= 10000; j++)
        {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j - coins[i] >= 0)
                dp[i % 2][j] += dp[i % 2][j - coins[i]];
        }
    }

    cout << dp[(n - 1) % 2][k] << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}