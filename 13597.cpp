#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << a << '\n';
    else if (a > b)
        cout << a << '\n';
    else
        cout << b << '\n';
    return 0;
}