#include <iostream>
using namespace std;

int n, k;
int coins[100];
int dp[100][10001];

// dp[i][j]는 i번째 동전까지 고려하였을 때 가치의 합이 j인 동전의 최소 개수
// dp[i][j] = min(dp[i - 1][j - coins[i] * k] + k) (0 <= k, coins[i] * k <= j)
// dp[i][j] = min(dp[i][j - coins[i]] + 1, dp[i - 1][j])

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
    for (int j = 0; j <= k; j++)
        dp[0][j] = (j % coins[0] == 0 ? j / coins[0] : 1234567890);

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = min((j - coins[i] >= 0 ? dp[i][j - coins[i]] + 1 : 1234567890), dp[i - 1][j]);


    cout << (dp[n - 1][k] >= 1234567890 ? -1 : dp[n - 1][k]) << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}