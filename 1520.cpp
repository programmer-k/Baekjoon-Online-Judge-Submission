#include <iostream>
#include <cassert>
using namespace std;

int m, n;
int map[500][500];
int dp[500][500];

// if dp[i][j] is k, then there are k routes given the position (i, j).

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
}

int Search(int row, int col)
{
    int cnt = 0;
    assert(row >= 0 && row < m);
    assert(col >= 0 && col < n);

    // dp table check
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    // destination
    if (row == m - 1 && col == n - 1)
    {
        return 1;
    }

    // right direction: (row, col + 1)
    if (col + 1 < n && map[row][col] > map[row][col + 1])
    {
        cnt += Search(row, col + 1);
    }
    // down direction: (row + 1, col)
    if (row + 1 < m && map[row][col] > map[row + 1][col])
    {
        cnt += Search(row + 1, col);
    }
    // left direction: (row, col - 1)
    if (col - 1 >= 0 && map[row][col] > map[row][col - 1])
    {
        cnt += Search(row, col - 1);
    }
    // up direction: (row - 1, col)
    if (row - 1 >= 0 && map[row][col] > map[row - 1][col])
    {
        cnt += Search(row - 1, col);
    }

    if (cnt != 0)
        return dp[row][col] = cnt;
    else
        return dp[row][col] = 0;
}

void Solve()
{
    cout << Search(0, 0) << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}