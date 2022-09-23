#include <iostream>
using namespace std;

int main(void)
{
    int l;
    cin >> l;
    if (l % 5 == 0)
        cout << l / 5 << '\n';
    else
        cout << l / 5 + 1 << '\n';
    return 0;
}