#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> edges;
vector<int> visit_order;

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;

  edges.resize(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int node1, node2;
    cin >> node1 >> node2;
    edges[node1].push_back(node2);
    edges[node2].push_back(node1);
  }

  visit_order.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> visit_order[i];
}

void BreadthFirstSearch(vector<int>& visited) {
  queue<int> q;
  q.push(1);
  visited[1] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int next_node : edges[node]) {
      if (visited[next_node] == -1) {
        q.push(next_node);
        visited[next_node] = visited[node] + 1;
      }
    }
  }
}

void Solve() {
  vector<int> visited(n + 1, -1);
  BreadthFirstSearch(visited);

  int max_level = *max_element(visited.begin(), visited.end());
  vector<vector<int>> levels(max_level + 1);
  for (int i = 1; i <= n; ++i)
    levels[visited[i]].push_back(i);

  bool is_valid = true;
  int from = 0;
  for (int i = 0; i < ssize(levels); ++i) {
    int len = ssize(levels[i]);
    sort(levels[i].begin(), levels[i].end());
    sort(visit_order.begin() + from, visit_order.begin() + from + len);
    
    for (int j = 0; j < len; ++j)
      if (levels[i][j] != visit_order[from + j])
        is_valid = false;

    from += len;
  }

  if (is_valid)
    cout << "1\n";
  else
    cout << "0\n";
}

int main() {
  GetInput();
  Solve();
  return 0;
}
