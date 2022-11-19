#include <iostream>
using namespace std;

int n;
int arr[100000];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solve()
{
    int answer = 1234567890;
    int start = 0, end = n - 1;

    while (start != end)
    {
        int sum = arr[start] + arr[end];
        int absolute = abs(sum);
        answer = (abs(answer) < absolute ? answer : sum);
        (sum > 0 ? end-- : start++);
    }

    cout << answer << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}