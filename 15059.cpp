#include <iostream>
using namespace std;

int main(void)
{
    int ca, ba, pa;
    cin >> ca >> ba >> pa;
    int cr, br, pr;
    cin >> cr >> br >> pr;
    int cnt = 0;
    if (ca < cr)
        cnt += cr - ca;
    if (ba < br)
        cnt += br - ba;
    if (pa < pr)
        cnt += pr - pa;
    cout << cnt << '\n';
    return 0;
}