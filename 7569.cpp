#include <iostream>
#include <queue>
using namespace std;

struct Quad
{
    int row;
    int col;
    int height;
    int depth;
};

int row, col, height, dep;
int tomatoes[100][100][100];
queue<Quad> q;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> col >> row >> height;
    for (int k = 0; k < height; k++)
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin >> tomatoes[k][i][j];
}

void BFS()
{
    while (!q.empty())
    {
        Quad quad = q.front();
        q.pop();

        int r = quad.row;
        int c = quad.col;
        int h = quad.height;
        int depth = quad.depth;
        dep = depth;

        if (r > 0 && tomatoes[h][r - 1][c] == 0)
        {
            tomatoes[h][r - 1][c] = 1;
            q.push({ r - 1, c, h, depth + 1});
        }
        if (r < row - 1 && tomatoes[h][r + 1][c] == 0)
        {
            tomatoes[h][r + 1][c] = 1;
            q.push({ r + 1, c, h, depth + 1});
        }
        if (c > 0 && tomatoes[h][r][c - 1] == 0)
        {
            tomatoes[h][r][c - 1] = 1;
            q.push({ r, c - 1, h, depth + 1});
        }
        if (c < col - 1 && tomatoes[h][r][c + 1] == 0)
        {
            tomatoes[h][r][c + 1] = 1;
            q.push({ r, c + 1, h, depth + 1});
        }
        if (h > 0 && tomatoes[h - 1][r][c] == 0)
        {
            tomatoes[h - 1][r][c] = 1;
            q.push({ r, c, h - 1, depth + 1});
        }
        if (h < height - 1 && tomatoes[h + 1][r][c] == 0)
        {
            tomatoes[h + 1][r][c] = 1;
            q.push({ r, c, h + 1, depth + 1});
        }
    }
}

void Solve()
{
    for (int k = 0; k < height; k++)
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (tomatoes[k][i][j] == 1)
                    q.push({ i, j, k, 0 });
    
    BFS();

    bool isUnderdone = false;
    for (int k = 0; k < height; k++)
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (tomatoes[k][i][j] == 0)
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