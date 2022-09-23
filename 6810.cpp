#include <iostream>
using namespace std;

int isbn[13] = { 9, 7, 8, 0, 9, 2, 1, 4, 1, 8, };

int main(void)
{
    int total = 0;
    cin >> isbn[10] >> isbn[11] >> isbn[12];
    for (int i = 0; i < 13; i++)
    {
        if (i % 2 == 0)
            total += isbn[i];
        else
            total += isbn[i] * 3;
    }
    cout << "The 1-3-sum is " << total << '\n';
    return 0;
}