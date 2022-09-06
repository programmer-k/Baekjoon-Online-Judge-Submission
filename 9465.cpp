#include <iostream>
using namespace std;

int t, n;
int stickers[2][100000];
int answer[2][100000];

// answer[i][j]에는 왼쪽부터 sticker[i][j]까지 선택했을 때 스티커의 최댓값이다.

void GetInput1()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
}

void GetInput2()
{
    cin >> n;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> stickers[i][j];
}

void Solve()
{
    answer[0][0] = stickers[0][0];
    answer[1][0] = stickers[1][0];
    answer[0][1] = stickers[1][0] + stickers[0][1];
    answer[1][1] = stickers[0][0] + stickers[1][1];

    for (int i = 1; i < n; i++)
    {
        answer[0][i] = max(answer[1][i - 1], answer[1][i - 2]) + stickers[0][i];
        answer[1][i] = max(answer[0][i - 1], answer[0][i - 2]) + stickers[1][i];
    }

    cout << max(answer[0][n - 1], answer[1][n - 1]) << '\n';
}

int main(void)
{
    GetInput1();
    for (int i = 0; i < t; i++)
    {
        GetInput2();
        Solve();
    }

    return 0;
}