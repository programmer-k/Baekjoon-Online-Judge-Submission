#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> edges[200001];
int visited[200001];

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> r;
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    edges[from].push_back(to);
    edges[to].push_back(from);
  }
}

void BreadthFirstSearch() {
  int cnt = 1;
  queue<int> q;
  visited[r] = cnt;
  q.push(r);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (unsigned int i = 0; i < edges[node].size(); ++i) {
      int next_node = edges[node][i];

      if (visited[next_node] != 0)
        continue;
      
      visited[next_node] = ++cnt;
      q.push(next_node);
    }
  }
}

void Solve() {
  for (int i = 1; i <= n; ++i)
    sort(edges[i].begin(), edges[i].end(), greater<int>());
  BreadthFirstSearch();
  for (int i = 1; i <= n; ++i)
    cout << visited[i] << '\n';
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}