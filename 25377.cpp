#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int mininum = 1234567890;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a <= b)
            mininum = min(mininum, b);
    }
    if (mininum == 1234567890)
        cout << -1 << '\n';
    else
        cout << mininum << '\n';
    return 0;
}