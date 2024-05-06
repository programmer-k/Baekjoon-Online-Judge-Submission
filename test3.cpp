#include <iostream>
using namespace std;

int t;
int n, k;
long long x;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
}

void Solve()
{
    int from = 1;
    int to = k;
    long long min = (long long) (from + to) * (to - from + 1) / 2;
    
    from = n - k + 1;
    to = n;
    long long max = (long long) (from + to) * (to - from + 1) / 2;

    if (x >= min && x <= max)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main(void)
{
    GetInput();
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k >> x;
        Solve();
    }
    return 0;
}