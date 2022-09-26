#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    cout << 1.0 / (1 + pow(10.0, (b - a) / 400.0)) << '\n';
    return 0;
}