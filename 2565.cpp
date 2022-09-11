#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> lines;
int dp[100];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0 ; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        lines.push_back(p);
    }

    sort(lines.begin(), lines.end());
}

void Solve()
{
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        int maximum = 0;
        for (unsigned int j = 0; j < i; j++)
            if (lines[i].second > lines[j].second)
                maximum = max(maximum, dp[j]);
        
        dp[i] = maximum + 1;
    }

    int global_maximum = 0;
    for (int i = 0; i < n; i++)
        global_maximum = max(global_maximum, dp[i]);
    cout << n - global_maximum << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}