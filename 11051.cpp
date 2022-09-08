#include <iostream>
using namespace std;

int n, k;
int dp[1001][1001];

// d[n][k] = dp[n - 1][k - 1] + dp[n - 1][k];

int Solve(int a, int b)
{
    if (dp[a][b])
        return dp[a][b];

    if (b == 1)
        return dp[a][b] = a;
    else if (a == b || b == 0)
        return dp[a][b] = 1;

    int num1 = Solve(a - 1, b - 1);
    int num2 = Solve(a - 1, b);
    return dp[a][b] = (num1 + num2) % 10007;
}

int main(void)
{
    cin >> n >> k;
    cout << Solve(n, k)<< '\n';
    return 0;
}