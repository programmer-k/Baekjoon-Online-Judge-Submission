#include <iostream>
#include <algorithm>
using namespace std;

long long n;
int answer[50001];

// answer[i] = min(answer[i - k * k]) + 1
// k * k <= i

int main(void)
{
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        int minimum = 1234567890;
        for (int k = 1; k * k <= i; k++)
            minimum = min(minimum, answer[i - k * k]);
        answer[i] = minimum + 1;
    }

    cout << answer[n] << endl;
    return 0;
}