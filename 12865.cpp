#include <iostream>
#include <utility>
using namespace std;

int n, k;
pair<int, int> weightVal[100];
int dp[100][100001];

// dp[i][j]는 i번째 물건까지 고려하였을 때 무게의 합이 j를 넘지 않는 가치합의 최댓값
// dp[i][j] = max(dp[i - 1][j - currentWeight] + currentVal, dp[i - 1][j]);

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> weightVal[i].first >> weightVal[i].second;
}

void Solve()
{
    for (int j = 1; j <= k; j++)
        if (weightVal[0].first <= j)
            dp[0][j] = weightVal[0].second;

    for (int i = 1; i < n; i++)
        for (int j = 1; j <= k; j++)
            if (j - weightVal[i].first >= 0)
                dp[i][j] = max(dp[i - 1][j - weightVal[i].first] + weightVal[i].second, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];

    cout << dp[n - 1][k] << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}