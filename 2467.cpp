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
    int answer = 2114567890;
    int answerVal1 = -1, answerVal2 = -1;
    int start = 0, end = n - 1;

    while (start != end)
    {
        //cout << arr[start] << ", " << arr[end] << '\n';
        int absolute = abs(arr[start] + arr[end]);
        if (answer > absolute)
        {
            answerVal1 = arr[start];
            answerVal2 = arr[end];
            answer = absolute;
            //cout << answerVal1 << ' ' << answerVal2 << '\n';
        }
        (arr[start] + arr[end] > 0 ? end-- : start++);
    }

    //cout << "out" << endl;
    cout << answerVal1 << ' ' << answerVal2 << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}