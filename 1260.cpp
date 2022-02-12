#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
bool graph[1001][1001];
bool visited[1001], will_visit[1001];
queue<int> q;

void GetInput()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1][vertex2] = graph[vertex2][vertex1]= true;
    }
}

void DFS(int vertex)
{
    cout << vertex << ' ';
    visited[vertex] = true;

    for (int i = 1; i <= n; i++)
        if (graph[vertex][i] && !visited[i])
            DFS(i);
}

void BFS()
{
    will_visit[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        cout << top << ' ';
        
        for (int i = 1; i <= n; i++)
        {
            if (graph[top][i] && !will_visit[i])
            {
                will_visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main(void)
{
    GetInput();
    DFS(v); cout << '\n';
    BFS(); cout << '\n';
    return 0;
}