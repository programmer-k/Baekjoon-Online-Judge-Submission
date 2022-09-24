#include <iostream>
using namespace std;

int main(void)
{
    long long r, c, n;
    cin >> r >> c >> n;
    if (r % n != 0)
        r += n - r % n;
    if (c % n != 0)
        c += n - c % n;
    cout << (r / n) * (c / n) << '\n';
    return 0;
}