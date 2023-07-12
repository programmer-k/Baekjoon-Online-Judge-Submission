#include <iostream>
using namespace std;

int t;
long long dp[101] = { -1, 1, 1, 1, 2, 2, };


int main(void)
{
    cin >> t;

    // DP Table 채우기
    for (int i = 6; i <= 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}