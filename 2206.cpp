#include <iostream>
#include <queue>
using namespace std;

struct BFSInfo
{
    int row;
    int col;
    int depth;
    int breakWallCntLeft;
};

int n, m;
int map[1000][1000];
bool willVisit[1000][1000][2];
queue<BFSInfo> q;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    cin.get();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            map[i][j] = cin.get() - '0';
        cin.get();
    }
}

bool BFS()
{
    while (!q.empty())
    {
        int row = q.front().row;
        int col = q.front().col;
        int depth = q.front().depth;
        bool breakWallCntLeft = q.front().breakWallCntLeft;
        q.pop();

        if (row == n - 1 && col == m - 1)
        {
            cout << depth << '\n';
            return true;
        }

        if (row > 0)
        {
            if (map[row - 1][col] && !willVisit[row - 1][col][breakWallCntLeft - 1] && breakWallCntLeft)
            {
                willVisit[row - 1][col][breakWallCntLeft - 1] = true;
                q.push({ row - 1, col, depth + 1, breakWallCntLeft - 1 });
            }
            else if (!map[row - 1][col] && !willVisit[row - 1][col][breakWallCntLeft])
            {
                willVisit[row - 1][col][breakWallCntLeft] = true;
                q.push({ row - 1, col, depth + 1, breakWallCntLeft });
            }
        }
        if (row < n - 1)
        {
            if (map[row + 1][col] && !willVisit[row + 1][col][breakWallCntLeft - 1] && breakWallCntLeft)
            {
                willVisit[row + 1][col][breakWallCntLeft - 1] = true;
                q.push({ row + 1, col, depth + 1, breakWallCntLeft - 1 });
            }
            else if (!map[row + 1][col] && !willVisit[row + 1][col][breakWallCntLeft])
            {
                willVisit[row + 1][col][breakWallCntLeft] = true;
                q.push({ row + 1, col, depth + 1, breakWallCntLeft });
            }
        }
        if (col > 0)
        {
            if (map[row][col - 1] && !willVisit[row][col - 1][breakWallCntLeft - 1] && breakWallCntLeft)
            {
                willVisit[row][col - 1][breakWallCntLeft - 1] = true;
                q.push({ row, col - 1, depth + 1, breakWallCntLeft - 1 });
            }
            else if (!map[row][col - 1] && !willVisit[row][col - 1][breakWallCntLeft])
            {
                willVisit[row][col - 1][breakWallCntLeft] = true;
                q.push({ row, col - 1, depth + 1, breakWallCntLeft });
            }
        }
        if (col < m - 1)
        {
            if (map[row][col + 1] && !willVisit[row][col + 1][breakWallCntLeft - 1] && breakWallCntLeft)
            {
                willVisit[row][col + 1][breakWallCntLeft - 1] = true;
                q.push({ row, col + 1, depth + 1, breakWallCntLeft - 1 });
            }
            else if (!map[row][col + 1] && !willVisit[row][col + 1][breakWallCntLeft])
            {
                willVisit[row][col + 1][breakWallCntLeft] = true;
                q.push({ row, col + 1, depth + 1, breakWallCntLeft });
            }
        }
    }

    return false;
}

void Solve()
{
    willVisit[0][0][1] = true;
    q.push({ 0, 0, 1, 1 });
    if (!BFS())
        cout << -1 << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}