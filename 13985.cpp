#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    char ch;
    cin >> a >> ch >> b >> ch >> c;
    if (a + b == c)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}