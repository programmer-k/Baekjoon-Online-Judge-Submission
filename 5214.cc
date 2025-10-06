#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, k, m;
vector<vector<int>> hyper_tubes(1'000, vector<int>(1'000));
vector<set<int>> hyper_tube_sets(1'000);

void GetInput() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k >> m;

  for (int i = 0; i < m; ++i)
    for (int j = 0; j < k; ++j)
      cin >> hyper_tubes[i][j];
}

int BreadthFirstSearch() {
  queue<int> q;
  vector<int> node_visited(n + 1, -1);
  vector<bool> set_visited(m);
  q.push(1);
  node_visited[1] = 1;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int i = 0; i < m; ++i) {
      if (!set_visited[i] && hyper_tube_sets[i].contains(node)) {
        set_visited[i] = true;
        for (int j = 0; j < k; ++j) {
          int next_node = hyper_tubes[i][j];
          if (node_visited[next_node] == -1) {
            q.push(next_node);
            node_visited[next_node] = node_visited[node] + 1;
          }
        }
      }
    }
  }

  return node_visited[n];
}

void Solve() {
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < k; ++j)
      hyper_tube_sets[i].insert(hyper_tubes[i][j]);

  cout << BreadthFirstSearch() << '\n';
}

int main() {
  GetInput();
  Solve();
  return 0;
}
