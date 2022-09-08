#include <iostream>
using namespace std;

int t, n;
int arr[1000];
int dp[1000];

// dp[i]는 i에서 끝나는 최대 합
// dp[i] = max(dp[i - 1] + arr[i], arr[i]);

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        
        dp[0] = arr[0];
        for (int j = 1; j < n; j++)
            dp[j] = max(dp[j - 1] + arr[j], arr[j]);
        
        int maximum = -1234567890;
        for (int j = 0; j < n; j++)
            maximum = max(maximum, dp[j]);
        
        cout << maximum << '\n';
    }
    return 0;
}