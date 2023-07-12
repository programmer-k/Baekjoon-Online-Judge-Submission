#include <iostream>
#include <algorithm>
using namespace std;

int n;
int boxes[1000];
int dp[1000];

void GetInput()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> boxes[i];
}

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        int maximum = 0;
        for (int j = 0; j < i; j++)
        {
            if (boxes[i] > boxes[j])
                maximum = max(maximum, dp[j]);
        }
        dp[i] = maximum + 1;
    }

    int maximum = -1;
    for (int i = 0; i < n; i++)
        maximum = max(maximum, dp[i]);
    
    cout << maximum << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}