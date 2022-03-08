#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

struct BFSInfo
{
    int row;
    int col;
    int depth;
    int type;
};

int tc;
int w, h;
pair<int, int> personPos;
vector<pair<int, int>> firePos;
char building[1000][1000];
bool willVisit[1000][1000];
queue<BFSInfo> q;

void GetInput1()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> tc;
}

void GetInput2()
{
    firePos.clear();
    while (!q.empty())
        q.pop();

    cin >> w >> h;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            willVisit[i][j] = false;
            cin >> building[i][j];
            
            if (building[i][j] == '@')
                personPos = { i, j };
            else if (building[i][j] == '*')
                firePos.push_back({ i, j });
        }
}

bool BFS()
{
    while (!q.empty())
    {
        int row = q.front().row;
        int col = q.front().col;
        int depth = q.front().depth;
        int type = q.front().type;
        q.pop();

        if (type == 0 && (row == 0 || row == h - 1 || col == 0 || col == w - 1))
        {
            cout << depth << '\n';
            return true;
        }

        if (type == 1)
        {
            if (row > 0 && (building[row - 1][col] == '.' || building[row - 1][col] == '@'))
            {
                building[row - 1][col] = '*';
                q.push({ row - 1, col, depth + 1, type });
            }
            if (row < h - 1 && (building[row + 1][col] == '.' || building[row + 1][col] == '@'))
            {
                building[row + 1][col] = '*';
                q.push({ row + 1, col, depth + 1, type });
            }
            if (col > 0 && (building[row][col - 1] == '.' || building[row][col - 1] == '@'))
            {
                building[row][col - 1] = '*';
                q.push({ row, col - 1, depth + 1, type });
            }
            if (col < w - 1 && (building[row][col + 1] == '.' || building[row][col + 1] == '@'))
            {
                building[row][col + 1] = '*';
                q.push({ row, col + 1, depth + 1, type });
            }
        }
        else
        {
            if (building[row - 1][col] == '.' && !willVisit[row - 1][col])
            {
                willVisit[row - 1][col] = true;
                q.push({ row - 1, col, depth + 1, type });
            }
            if (building[row + 1][col] == '.' && !willVisit[row + 1][col])
            {
                willVisit[row + 1][col] = true;
                q.push({ row + 1, col, depth + 1, type });
            }
            if (building[row][col - 1] == '.' && !willVisit[row][col - 1])
            {
                willVisit[row][col - 1] = true;
                q.push({ row, col - 1, depth + 1, type });
            }
            if (building[row][col + 1] == '.' && !willVisit[row][col + 1])
            {
                willVisit[row][col + 1] = true;
                q.push({ row, col + 1, depth + 1, type });
            }
        }
    }

    return false;
}

void Solve()
{
    for (unsigned int i = 0; i < firePos.size(); i++)
    {
        willVisit[firePos[i].first][firePos[i].second] = true;
        q.push({ firePos[i].first, firePos[i].second, 1, 1 });
    }

    willVisit[personPos.first][personPos.second] = true;
    q.push({ personPos.first, personPos.second, 1, 0 });

    if (!BFS())
        cout << "IMPOSSIBLE" << '\n';
}

int main(void)
{
    GetInput1();
    for (int i = 0; i < tc; i++)
    {
        GetInput2();
        Solve();
    }
    return 0;
}