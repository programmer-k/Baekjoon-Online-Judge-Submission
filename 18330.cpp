#include <iostream>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    if (n <= k + 60)
        cout << n * 1500 << '\n';
    else
        cout << (k + 60) * 1500 + (n - k - 60) * 3000 << '\n';
    return 0;
}