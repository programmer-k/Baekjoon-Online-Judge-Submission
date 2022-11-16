#include <iostream>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            cout << a + b << ' ' << a * b << '\n';
        }
    }
    return 0;
}