#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int time = 0;
    if (a < 0)
    {
        time += -a * c;
        time += d;
        time += b * e;
    }
    else
    {
        time += (b - a) * e;
    }
    cout << time << '\n';
    return 0;
}