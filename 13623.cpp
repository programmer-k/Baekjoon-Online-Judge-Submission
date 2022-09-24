#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    if (b == c && a != b)
        cout << "A\n";
    else if (b != a && a == c)
        cout << "B\n";
    else if (c != a && a == b)
        cout << "C\n";
    else
        cout << "*\n";
    return 0;
}