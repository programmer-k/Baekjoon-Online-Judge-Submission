#include <iostream>
using namespace std;

int main(void)
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long result1 = (a * b / (double) c);
    long long result2 = ((double) a / b * c);
    cout << max(result1, result2) << '\n';
    return 0;
}