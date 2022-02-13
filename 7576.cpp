#include <iostream>
#include <queue>
using namespace std;

struct Triple
{
    int row;
    int col;
    int depth;
};

int row, col, dep;
int tomatoes[1000][1000];
queue<Triple> q;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> col >> row;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> tomatoes[i][j];
}

void BFS()
{
    while (!q.empty())
    {
        Triple triple = q.front();
        q.pop();

        int r = triple.row;
        int c = triple.col;
        int depth = triple.depth;
        dep = max(dep, depth);

        if (r > 0 && tomatoes[r - 1][c] == 0)
        {
            tomatoes[r - 1][c] = true;
            q.push({ r - 1, c, depth + 1});
        }
        if (r < row - 1 && tomatoes[r + 1][c] == 0)
        {
            tomatoes[r + 1][c] = true;
            q.push({ r + 1, c, depth + 1});
        }
        if (c > 0 && tomatoes[r][c - 1] == 0)
        {
            tomatoes[r][c - 1] = true;
            q.push({ r, c - 1, depth + 1});
        }
        if (c < col - 1 && tomatoes[r][c + 1] == 0)
        {
            tomatoes[r][c + 1] = true;
            q.push({ r, c + 1, depth + 1});
        }
    }
}

void Solve()
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (tomatoes[i][j] == 1)
                q.push({ i, j, 0 });
    
    BFS();

    bool isUnderdone = false;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (tomatoes[i][j] == 0)
                isUnderdone = true;
    
    if (isUnderdone)
        cout << -1 << '\n';
    else
        cout << dep << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}