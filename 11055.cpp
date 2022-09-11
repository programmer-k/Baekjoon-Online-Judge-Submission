#include <iostream>
using namespace std;

int n;
int arr[1000];
int dp[1000];

// dp[i]는 arr[i]를 끝으로 하는 합이 가장 큰 증가 부분 수열의 값이 저장되어 있다.
// dp[i] = max(dp[j]) + arr[i]; (0 <= j < i, arr[j] < arr[i])
// Intuition: 이미 구해져 있는 모든 경우의 수에 대해 붙일 수 있는 것들에 대해서만 확인한다.

void GetInput()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        int maximum = 0;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                maximum = max(maximum, dp[j]);
        
        dp[i] = maximum + arr[i];
    }

    int global_maximum = 0;
    for (int i = 0; i < n; i++)
        global_maximum = max(global_maximum, dp[i]);
    cout << global_maximum << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}