#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int k;
int v, e;
vector<int> edges[20001];
int visited[20001];

void GetInput1() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k;
}

void GetInput2() {
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i <= 20000; ++i)
    edges[i].clear();

  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}

void BreadthFirstSearch(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 1;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int next_node : edges[node]) {
      if (visited[next_node] == 0) {
        q.push(next_node);
        visited[next_node] = visited[node] == 1 ? 2 : 1;
      }
    }
  }
}

bool IsBipartiteGraph() {
  for (int i = 1; i <= v; ++i) {
    int node_color = visited[i];
    for (int next_node : edges[i]) {
      int next_node_color = visited[next_node];
      if (node_color == next_node_color)
        return false;
    }
  }

  return true;
}

void Solve() {
  for (int i = 1; i <= v; ++i)
    if (visited[i] == 0)
      BreadthFirstSearch(i);

  if (IsBipartiteGraph())
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(void) {
  GetInput1();
  for (int i = 0; i < k; ++i) {
    GetInput2();
    Solve();
  }
  return 0;
}