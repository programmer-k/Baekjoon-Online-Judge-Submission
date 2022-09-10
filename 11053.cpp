#include <iostream>
using namespace std;

int n;
int arr[1000];
int dp[1000] = { 1, };

// dp[i]는 i번째에서 끝나는 가장 긴 증가하는 부분 수열
// dp[i] = max(dp[j]) + 1 (0 <= j < i, arr[j] < arr[i])
// Intuition: 이전에 계산한 가장 긴 증가하는 부분 수열 중 arr[i]를 붙일 수 있는 제일 긴 수열을 찾는다.
// 따라서 arr[j] < arr[i]인 dp 배열만 참조하고 (크지 않다면 붙일 수 없으므로 정답 후보 대상이 아님)
// 제일 긴 증가하는 부분 수열이 어디에 있는지 모르므로 모든 후보를 다 확인한다.

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

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
                maximum = max(dp[j], maximum);

        dp[i] = maximum + 1;
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