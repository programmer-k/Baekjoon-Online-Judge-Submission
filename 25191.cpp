#include <iostream>
using namespace std;

int main(void)
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n < a / 2 + b)
        cout << n << '\n';
    else
        cout << a / 2 + b << '\n';
    return 0;
}