#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, k, x;
vector<int> edges[300001];
int visited[300001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k >> x;
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    edges[from].push_back(to);
  }
}

void BreadthFirstSearch(int start) {
  queue<int> q;
  memset(visited, -1, sizeof(visited));
  q.push(start);
  visited[start] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (visited[node] == k)
      break;

    for (unsigned int i = 0; i < edges[node].size(); ++i) {
      int next_node = edges[node][i];

      if (visited[next_node] == -1) {
        q.push(next_node);
        visited[next_node] = visited[node] + 1;
      }
    }
  }
}

void Solve() {
  BreadthFirstSearch(x);

  bool print = false;
  for (int i = 1; i <= n; ++i)
    if (visited[i] == k) {
      print = true;
      cout << i << '\n';
    }
  
  if (!print)
    cout << -1 << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}