#include <iostream>
using namespace std;

int n;
int triangle[500][500];
int dp[500][500];

// dp[i][j]는 맨 위에서 triangle[i][j]까지 왔을 때 최대 합
// dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];
}

void Solve()
{
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }

    int global_maximum = -1;
    for (int i = 0; i < n; i++)
        global_maximum = max(global_maximum, dp[n - 1][i]);
    cout << global_maximum << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}