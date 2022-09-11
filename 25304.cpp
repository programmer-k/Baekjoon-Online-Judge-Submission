#include <iostream>
using namespace std;

int x, n;
int total;

int main(void)
{
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        total += a * b;
    }

    if (total == x)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}