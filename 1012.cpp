#include <iostream>
using namespace std;

int t, m, n, k;
bool graph[50][50];
bool visited[50][50];

void GetInput1()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
}

void GetInput2()
{
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
        {
            graph[i][j] = false;
            visited[i][j] = false;
        }

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int row, col;
        cin >> col >> row;
        graph[row][col] = true;
    }
}

void MarkConnectedComponent(int row, int col)
{
    visited[row][col] = true;

    if (row > 0 && graph[row - 1][col] && !visited[row - 1][col])
        MarkConnectedComponent(row - 1, col);
    if (row < n - 1 && graph[row + 1][col] && !visited[row + 1][col])
        MarkConnectedComponent(row + 1, col);
    if (col > 0 && graph[row][col - 1] && !visited[row][col - 1])
        MarkConnectedComponent(row, col - 1);
    if (col < m - 1 && graph[row][col + 1] && !visited[row][col + 1])
        MarkConnectedComponent(row, col + 1);
}

void Solve()
{
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] && !visited[i][j])
            {
                MarkConnectedComponent(i, j);
                ans++;
            }


    cout << ans << '\n';
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