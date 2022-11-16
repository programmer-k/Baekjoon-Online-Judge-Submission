#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c <= 4)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
    return 0;
}