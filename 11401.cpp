#include <iostream>
using namespace std;

int n, k;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
}

int BinomialCoefficient(int num1, int num2)
{
    if (num2 == 1 || num1 == num2 + 1)
        return num1;
    else if (num2 == 0)
        return 1;

    int intermediate1 = BinomialCoefficient(num1 - 1, num2 - 1);
    int intermediate2 = BinomialCoefficient(num1 - 1, num2);
    return (intermediate1 + intermediate2) % 1000000007;
}

int main(void)
{
    GetInput();
    cout << BinomialCoefficient(n, k) << '\n';
    return 0;
}