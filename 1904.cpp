#include <iostream>
using namespace std;

int n;
int answer[1000001] = { 0, 1, 2, };

// answer[i] = answer[i - 1] + answer[i - 2];

int main(void)
{
    cin >> n;
    for (int i = 3; i <= n; i++)
        answer[i] = (answer[i - 1] + answer[i - 2]) % 15746;
    cout << answer[n] << endl;
    return 0;
}