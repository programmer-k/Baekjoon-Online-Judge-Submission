#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Triple
{
    int row;
    int col;
    int depth;
};

int n, m;
string maze[100];
bool will_visit[100][100];
queue<Triple> q;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> maze[i];
}

void BFS()
{
    while (!q.empty())
    {
        Triple top = q.front();
        int row = top.row;
        int col = top.col;
        int depth = top.depth;
        q.pop();

        if (row == n - 1 && col == m - 1)
        {
            cout << depth << '\n';
            return;
        }

        // Enqueue
        if (row > 0 && maze[row - 1][col] == '1' && !will_visit[row - 1][col])
        {
            will_visit[row - 1][col] = true;
            q.push({ row - 1, col, depth + 1 });
        }
        if (row < n - 1 && maze[row + 1][col] == '1' && !will_visit[row + 1][col])
        {
            will_visit[row + 1][col] = true;
            q.push({ row + 1, col, depth + 1 });
        }
        if (col > 0 && maze[row][col - 1] == '1' && !will_visit[row][col - 1])
        {
            will_visit[row][col - 1] = true;
            q.push({ row, col - 1, depth + 1 });
        }
        if (col < m - 1 && maze[row][col + 1] == '1' && !will_visit[row][col + 1])
        {
            will_visit[row][col + 1] = true;
            q.push({ row, col + 1, depth + 1 });
        }
    }
}

void Solve()
{
    will_visit[0][0] = true;
    q.push({ 0, 0, 1 });
    BFS();
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}