#include <iostream>
using namespace std;

int main(void)
{
    int x, l, r;
    cin >> x >> l >> r;
    if (l <= x && x <= r)
        cout << x << '\n';
    else if (l > x)
        cout << l << '\n';
    else
        cout << r << '\n';
    return 0;
}