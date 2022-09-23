#include <iostream>
using namespace std;

int main(void)
{
    int n1, n2, n12;
    cin >> n1 >> n2 >> n12;
    cout << int ((n1 + 1) * (n2 + 1) / (double) (n12 + 1) - 1) << '\n';
    return 0;
}