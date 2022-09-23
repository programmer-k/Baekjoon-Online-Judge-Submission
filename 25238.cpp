#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    if (a * ((100 - b) / 100.0) >= 100)
        cout << 0 << '\n';
    else
        cout << 1 << '\n';
    return 0;
}