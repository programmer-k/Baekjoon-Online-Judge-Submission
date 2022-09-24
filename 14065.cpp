#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    double x;
    cin >> x;
    printf("%f\n", 3.785411784 / (x * 1609.344) * 100000);
    return 0;
}