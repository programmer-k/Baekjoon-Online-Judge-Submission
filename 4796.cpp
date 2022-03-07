#include <iostream>
using namespace std;

int l, p, v;
int count;

void GetInput()
{
    cin >> l >> p >> v;
}

void Solve()
{
    count++;
    cout << "Case " << count << ": " << v / p * l + (v % p <= l ? v % p : l) << '\n';
}

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    while (true)
    {
        GetInput();
        if (l == 0 && p == 0 && v == 0)
            break;
        Solve();
    }
    return 0;
}