#include <iostream>
using namespace std;

int n, k;
int dp[1001][1001];

// 선형
// dp[i][j]는 i 색상환에서 서로 다른 j개의 색을 선택하는 경우의 수
// dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j]


void GetInput()
{
    cin >> n >> k;
}

void Solve()
{
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
        }
    }

    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % 1000000003 << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}