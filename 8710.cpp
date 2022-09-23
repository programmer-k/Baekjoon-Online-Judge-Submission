#include <iostream>
using namespace std;

int main(void)
{
    int k, w, m;
    cin >> k >> w >> m;
    if ((w - k) % m == 0)
        cout << (w - k) / m << '\n';
    else
        cout << (w - k) / m + 1 << '\n';
    return 0;
}