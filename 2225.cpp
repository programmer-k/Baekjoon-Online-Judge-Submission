#include <iostream>
using namespace std;

const int BILLION = 1000000000;
int n, k;
int dp[201][201];

// dp[k][n] = sum(dp[k - 1][n - a]); (0 <= a <= n)

void GetInput()
{
    cin >> n >> k;
}

int CalcDP(int k, int n)
{
    //cout << "CalcDP(" << k << ", " << n << ")" << '\n';

    if (dp[k][n] != 0)
        return dp[k][n];
    
    long long sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += CalcDP(k - 1, n - i);
        sum %= BILLION;
    }

    return dp[k][n] = sum;
}

void Solve()
{
    // Base case initialization
    for (int i = 0; i <= 200; i++)
        dp[1][i] = 1;
    
    for (int i = 1; i <= 200; i++)
        dp[i][0] = 1;
    
    cout << CalcDP(k, n) << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}