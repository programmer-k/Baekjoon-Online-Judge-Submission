#include <iostream>
using namespace std;

int t;
int x, y, k;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
}

void Solve()
{
    cin >> x >> y >> k;

    if (x > y)
    {
        cout << x << '\n';
    }
    else
    {
        int answer = x + min(k, y - x) + (x + k >= y ? 0 : 2 * (y - (x + k)));
        cout << answer << '\n';
    }
}

int main(void)
{
    GetInput();
    for (int i = 0; i < t; i++)
        Solve();
    return 0;
}