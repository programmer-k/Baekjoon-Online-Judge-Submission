#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long paths[99999];
long long prices[100000];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
        cin >> paths[i];
    
    for (int i = 0; i < n; i++)
        cin >> prices[i];
}

void Solve()
{
    long long total = 0;
    long long path = 0;
    long long currentMinPrice = prices[0];

    for (int i = 0; i < n - 1; i++)
    {
        if (currentMinPrice > prices[i + 1] || i == n - 2)
        {

            total += currentMinPrice * (paths[i] + path);
            currentMinPrice = prices[i + 1];
            path = 0;
        }
        else
            path += paths[i];
    }

    cout << total << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}