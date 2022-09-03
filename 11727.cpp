#include <iostream>
using namespace std;

int n;
int answer[1001] = { 0, 1, 3, };

// answer[i] = answer[i - 1] + answer[i - 2] * 2;

int main(void)
{
    cin >> n;
    for (int i = 3; i <= n; i++)
        answer[i] = (answer[i - 1] + answer[i - 2] * 2) % 10007;
    cout << answer[n] << endl;
    return 0;
}