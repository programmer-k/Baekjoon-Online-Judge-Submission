#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int result = n % 8;
    if (result == 0)
        cout << 2 <<'\n';
    else if (result <= 5)
        cout << result << '\n';
    else if (result == 6)
        cout << 4 << '\n';
    else
        cout << 3 << '\n';
    return 0;
}