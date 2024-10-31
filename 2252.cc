#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> edges[32001];
int in_degrees[32001];

void GetInput() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }
}

void TopologySort() {
  vector<int> result;
  for (int i = 1; i <= n; ++i)
    for (int neighbor : edges[i])
      ++in_degrees[neighbor];

  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (in_degrees[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    result.push_back(node);

    for (int neighbor : edges[node])
      if (--in_degrees[neighbor] == 0)
        q.push(neighbor);
  }

  for (int node : result)
    cout << node << ' ';
  cout << '\n';
}

void Solve() {
  TopologySort();
}

int main(void) {
  GetInput();
  Solve();
  return 0;
}