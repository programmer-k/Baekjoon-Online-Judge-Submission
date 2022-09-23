#include <iostream>
using namespace std;

int main(void)
{
    int d, h, m;
    cin >> d >> h >> m;

    int remaining = 0;
    if (m >= 11)
        remaining = m - 11;
    else
    {
        h--;
        m += 60;
        remaining = m - 11;
    }

    if (h >= 11)
    {
        d--;
        h += 24;
    }
    remaining += (h - 11) * 60;

    remaining += (d - 11) * 24 * 60;
    if (remaining < 0)
        cout << -1 << '\n';
    else
        cout << remaining << '\n';

    return 0;
}