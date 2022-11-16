#include <iostream>
using namespace std;

int main(void)
{
    int n, highest = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, d, g;
        cin >> a >> d >> g;
        int score = a * (d + g);
        if (a == d + g)
            score *= 2;
        highest = max(highest, score);
    }
    cout << highest << '\n';
    return 0;
}