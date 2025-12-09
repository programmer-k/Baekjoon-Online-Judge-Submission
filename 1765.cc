#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n, m;
vector<vector<pair<int, char>>> edges;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> m;

  edges.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    char ch;
    int p, q;
    cin >> ch >> p >> q;

    edges[p].push_back({q, ch});
    edges[q].push_back({p, ch});
  }
}

int BreadthFirstSearch(int start, vector<int>& visited) {
  int count = 1;
  queue<int> q;
  q.push(start);
  visited[start] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (visited[node] == 1)
      count = 2;

    for (const pair<int, char>& next : edges[node]) {
      int next_node = next.first;
      char relationship = next.second;

      if (visited[next_node] == -1) {
        q.push(next_node);
        visited[next_node] =
            relationship == 'F' ? visited[node] : visited[node] + 1;
      }
    }
  }

  return count;
}

void Solve() {
  int total = 0;
  vector<int> visited(n + 1, -1);

  for (int i = 1; i <= n; ++i)
    if (visited[i] == -1)
      total += BreadthFirstSearch(i, visited);

  cout << total << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
