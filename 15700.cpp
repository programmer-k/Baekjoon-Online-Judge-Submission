#include <iostream>
using namespace std;

int main(void)
{
    long long n, m;
    cin >> n >> m;
    if (n % 2 != 0 && m % 2 != 0)
        cout << (n * m - 1) / 2 << '\n';
    else
        cout << n * m / 2 << '\n';
    return 0;
}