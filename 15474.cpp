#include <iostream>
using namespace std;

int main(void)
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int cost1 = 0, cost2 = 0;
    if (n % a == 0)
    {
        cost1 = n / a * b;
    }
    else
        cost1 = (n / a + 1) * b;
    
    if (n % c == 0)
    {
        cost2 = n / c * d;
    }
    else
        cost2 = (n / c + 1) * d;
    cout << min(cost1, cost2) << '\n';
    return 0;
}