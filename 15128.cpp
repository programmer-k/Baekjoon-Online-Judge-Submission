#include <iostream>
#include <numeric>
using namespace std;

int main(void)
{
    int p1, q1, p2, q2;
    cin >> p1 >> q1 >> p2 >> q2;

    int gcd1 = gcd(p1, q1);
    int gcd2 = gcd(p2, q2);
    p1 /= gcd1;
    q1 /= gcd1;
    p2 /= gcd2;
    q2 /= gcd2;

    if (p1 % q2 == 0)
        p1 /= q2;
    else
    {
        cout << "0\n";
        return 0;
    }
    if (p2 % q1 == 0)
        p2 /= q1;
    else
    {
        cout << "0\n";
        return 0;
    }
    if (p1 % 2 == 0 || p2 % 2 == 0)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}