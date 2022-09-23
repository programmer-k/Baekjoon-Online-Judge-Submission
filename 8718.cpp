#include <iostream>
using namespace std;

int main(void)
{
    long long x, k;
    cin >> x >> k;
    x *= 1000;
    k *= 1000;

    if (k + k / 2 + k / 4 > x)
        cout << 0 << '\n';
    else
    {
        if (k + k * 2 + k * 4 <= x)
            cout << k + k * 2 + k * 4 << '\n';
        else if (k + k * 2 + k / 2 <= x)
            cout << k + k * 2 + k /2 << '\n';
        else
            cout << k + k / 2 + k / 4 << '\n';
    }
    return 0;
}