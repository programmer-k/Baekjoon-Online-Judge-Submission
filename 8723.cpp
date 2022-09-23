#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
        cout << 2 << '\n';
    else if (c * c == a * a + b * b || a * a == b * b + c * c || b * b == a * a + c * c)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}