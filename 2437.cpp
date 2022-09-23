#include <iostream>
#include <algorithm>
using namespace std;

int n;
int weights[1000];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> weights[i];
}

void Solve()
{
    sort(weights, weights + n);

    // 현재까지 고려한 저울추들을 사용하면, 1부터 sum까지의 무게를 모두 표현할 수 있다.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + 1 < weights[i])
            break;
        sum += weights[i];
    }
    cout << sum + 1 << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}