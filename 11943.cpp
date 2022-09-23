#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(c + b, a + d) << '\n';
    return 0;
}