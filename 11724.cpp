#include <iostream>
using namespace std;

int n, m;
bool graph[1001][1001];
bool visited[1001];

void GetInput()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1][vertex2] = true;
        graph[vertex2][vertex1] = true;
    }
}

void DFS(int vertex)
{
    visited[vertex] = true;

    for (int i = 1; i <= n; i++)
        if (graph[vertex][i] && !visited[i])
            DFS(i);
}

void Solve()
{
    int connected_components = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            connected_components++;
        }
    }

    cout << connected_components << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}