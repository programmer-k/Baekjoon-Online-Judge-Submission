#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int result[3];
    result[0] = a2 * 2 + a3 * 4;
    result[1] = (a1 + a3) * 2;
    result[2] = a1 * 4 + a2 * 2;
    cout << min({ result[0], result[1], result[2] }) << '\n';
    return 0;
}