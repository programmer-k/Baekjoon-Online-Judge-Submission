#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        cout << min({a, b, c}) << '\n';
    }
    return 0;
}