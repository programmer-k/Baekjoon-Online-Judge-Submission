#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

double Calc(double num)
{
    double arr[5] = { 1, };
    for (int i = 1; i < 5; i++)
        arr[i] = arr[i - 1] * num;
    double total = 0;
    for (int i = 0; i < 5; i++)
        total += arr[i];
    return total;
}

int main(void)
{
    cout << setprecision(2);
    while (true)
    {
        double n;
        cin >> n;
        if (n == 0)
            break;
        printf("%.2lf\n", Calc(n));
    }
    return 0;
}